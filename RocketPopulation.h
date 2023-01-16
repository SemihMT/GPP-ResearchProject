#pragma once
#include "utils.h"
#include "Rocket.h"
#include <vector>

using namespace utils;
class RocketPopulation
{
public:
	RocketPopulation(const int lifeSpan, const Point2f& targetPoint);
	~RocketPopulation();
	void Update();
	void Draw();
	void Evaluate();
	void Selection();
	Rocket* AcceptReject(const float maxFitness);
private:
	std::vector<Rocket*> m_Rockets;
	std::vector<Rocket*> m_MatingPool;
	int m_PopSize{100};
	int m_LifeSpan{};
	int m_Count{};
	Point2f m_Target{};
};
