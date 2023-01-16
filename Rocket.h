#pragma once
#include "utils.h"
#include "RocketDNA.h"
using namespace utils;
class Rocket
{
public:
	Rocket(const Vector2f& startingPos, const Point2f& targetPoint);
	Rocket(const Vector2f& startingPos, const Point2f& targetPoint, std::vector<Vector2f> dna);
	void ApplyForce(const Vector2f& force);
	void Update(const int count);
	void Draw() const;
	void CalcFitness();
	float GetFitness(){return m_Fitness;}
	void SetFitness(float fitness){m_Fitness = fitness;}
	RocketDNA GetDNA(){return m_Dna;}
private:
	Vector2f m_Position{};
	Vector2f m_Velocity{};
	Vector2f m_Acceleration{};
	RocketDNA m_Dna;
	Point2f m_Target{};
	float m_Fitness{};
	

	

};
