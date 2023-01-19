#pragma once
#include "DNA.h"
struct Rocket
{
	Rocket(int lifespan, float mutationRate, int& count);
	Rocket(const DNA& dna, int& count);

	void ApplyForce(const Vector2f& f);
	void Update(const Vector2f& target, const Rectf& obstacle,float elapsedSec);
	void CalcFitness(const Vector2f& target);
	void Draw() const;

	

	Rectf m_Shape;
	Vector2f m_Pos;
	Vector2f m_Vel;
	Vector2f m_Acc;

	int& m_Count;
	int m_CompletionTime;
	int m_Lifespan;

	float m_Fitness;
	bool m_Finished;
	bool m_Crashed;

	DNA m_Dna;


};
