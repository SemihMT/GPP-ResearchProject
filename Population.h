#pragma once
#include "pch.h"
#include <vector>
#include <memory>
#include "Rocket.h"
struct Population
{
	Population(int populationSize,int lifespan, float mutationRate, const Vector2f& target,const Rectf& obstacle, int& count);
	float NaturalSelection();
	int GetFinished();
	void Selection();
	void Update(float elapsedSec);
	void Draw();




	std::vector<std::shared_ptr<Rocket>> m_Rockets;
	std::vector<std::shared_ptr<Rocket>> m_MatingPool;
	int m_PopulationSize;
	int& m_Count;
	Vector2f m_Target;
	int m_Lifespan;
	float m_MutationRate;
	Rectf m_Obstacle;
};
