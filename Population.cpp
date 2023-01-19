#include "Population.h"
Population::Population(int populationSize, int lifespan, float mutationRate, const Vector2f& target, const Rectf& obstacle, int& count) :
	m_PopulationSize{ populationSize }, 
	m_Lifespan{ lifespan },
	m_MutationRate{ mutationRate },
	m_Target{ target },
	m_Count{ count },
	m_Obstacle{obstacle}
{
	for (int i{}; i < m_PopulationSize; ++i)
	{
		m_Rockets.push_back(std::make_unique<Rocket>(lifespan, mutationRate, count));
	}
}

float Population::NaturalSelection()
{
	float maxFitness{};
	for (std::shared_ptr<Rocket> rocket : m_Rockets)
	{
		rocket->CalcFitness(m_Target);
		if (rocket->m_Fitness > maxFitness)
		{
			maxFitness = rocket->m_Fitness;
		}
	}

	for (std::shared_ptr<Rocket> rocket : m_Rockets)
	{
		rocket->m_Fitness /= maxFitness;
	}
	m_MatingPool.clear();
	for (std::shared_ptr<Rocket> rocket : m_Rockets)
	{
		int n{ int(rocket->m_Fitness * 100) };
		for (int i{}; i < n; ++i)
		{
			m_MatingPool.push_back(rocket);
		}
	}
	return maxFitness;
}

int Population::GetFinished()
{
	int count = 0;
	for (const auto& rocket : m_Rockets) {
		if (rocket->m_Finished)
			count++;
	}
	return count;
}

void Population::Selection()
{
	std::vector<std::shared_ptr<Rocket>> newRockets;
	for (int i = 0; i < m_Rockets.size(); i++) {
		int randomIndex = int(RandomNumber(int(m_MatingPool.size() )- 1));
		DNA parentA = m_MatingPool[randomIndex]->m_Dna;
		randomIndex = int(RandomNumber(int(m_MatingPool.size() )- 1));
		DNA parentB = m_MatingPool[randomIndex]->m_Dna;
		DNA child = parentA.Crossover(parentB);

		child.Mutate();

		newRockets.push_back(std::make_unique<Rocket>(child, m_Count));
	}

	m_Rockets = newRockets;
}

void Population::Update(float elapsedSec)
{
	for (std::shared_ptr<Rocket> rocket : m_Rockets) 
	{
		rocket->Update(m_Target,m_Obstacle,elapsedSec);
	}
}

void Population::Draw()
{
	for (std::shared_ptr<Rocket> rocket : m_Rockets) 
	{
		rocket->Draw();
	}
}
