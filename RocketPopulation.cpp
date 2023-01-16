#include "pch.h"
#include "RocketPopulation.h"

RocketPopulation::RocketPopulation(const int lifeSpan, const Point2f& targetPoint) :
	m_Rockets{},
	m_PopSize{ 100 },
	m_LifeSpan{ lifeSpan },
	m_Count{ 0 },
	m_Target{ targetPoint }
{
	for (int i{}; i < m_PopSize; ++i)
	{
		m_Rockets.push_back(new Rocket(Vector2f{ 423,0 }, m_Target));
	}
}

RocketPopulation::~RocketPopulation()
{
	for (int i{}; i < m_PopSize; ++i)
	{
		delete m_Rockets[i];
	}
	m_Rockets.clear();
}

void RocketPopulation::Update()
{
	if (m_Count < m_LifeSpan)
	{
		for (int i{}; i < m_PopSize; ++i)
		{
			m_Rockets[i]->Update(m_Count);
		}
	}
	++m_Count;
	if (m_Count > m_LifeSpan)
	{
		for (int i{}; i < m_PopSize; ++i)
		{
			delete m_Rockets[i];
		}
		m_Rockets.clear();


		for (int i{}; i < m_PopSize; ++i)
		{
			m_Rockets.push_back(new Rocket(Vector2f{ 423,0 }, m_Target));
		}
	}
}

void RocketPopulation::Draw()
{
	for (int i{}; i < m_PopSize; ++i)
	{
		m_Rockets[i]->Draw();
	}
}

void RocketPopulation::Evaluate()
{
	float maxFit{ 0 };
	for (int i{}; i < m_PopSize; ++i)
	{
		if (m_Rockets[i]->GetFitness() > maxFit)
		{
			maxFit = m_Rockets[i]->GetFitness();
		}
	}



	for (int i{}; i < m_PopSize; ++i)
	{
		m_Rockets[i]->SetFitness(m_Rockets[i]->GetFitness() / maxFit);
	}


}

void RocketPopulation::Selection()
{
	float maxFitness{ 0 };

	for (int i{ 0 }; i < m_Rockets.size(); ++i)
	{
		if (m_Rockets[i]->GetFitness() > maxFitness)
			maxFitness = m_Rockets[i]->GetFitness();
	}


	std::vector<Rocket*> newRockets{ m_Rockets.size() };
	for (int i{}; i < m_Rockets.size(); ++i)
	{
		auto parentA = AcceptReject(maxFitness);
		auto parentB = AcceptReject(maxFitness);

		auto child = parentA->GetDNA().CrossOver(&parentB->GetDNA());
		newRockets[i] = new Rocket(Vector2f{ 423,0 }, m_Target,child);
	}
	for(int i{}; i < m_Rockets.size(); ++i)
	{
		delete m_Rockets[i];
	}

	m_Rockets = newRockets;
}

Rocket* RocketPopulation::AcceptReject(const float maxFitness)
{
	int beSafe{ 0 };
	while (true)
	{
		int index{ utils::RandomInteger(0,int(m_Rockets.size()) - 1) };
		Rocket* partner{ m_Rockets[index] };
		float r{ utils::RandomFloat(0,maxFitness) };
		if (r < partner->GetFitness())
		{
			return partner;
		}
		++beSafe;

		if (beSafe > 10000)
			return nullptr;
	}

	return nullptr;
}
