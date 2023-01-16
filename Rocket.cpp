#include "pch.h"
#include "Rocket.h"

Rocket::Rocket(const Vector2f& startingPos, const Point2f& targetPoint) :
	m_Position{ startingPos },
	m_Velocity{ 0,0 },
	m_Acceleration{},
	m_Dna{},
	m_Target{targetPoint}
	
{
}

Rocket::Rocket(const Vector2f& startingPos, const Point2f& targetPoint, std::vector<Vector2f> dna):
	m_Position{ startingPos },
	m_Velocity{ 0,0 },
	m_Acceleration{},
	m_Dna{dna},
	m_Target{targetPoint}
{
}

void Rocket::ApplyForce(const Vector2f& force)
{
	m_Acceleration += force;
}

void Rocket::Update(const int count)
{
	ApplyForce(m_Dna.GetGenes()[count]);
	
	m_Velocity += m_Acceleration;
	m_Position += m_Velocity;
	m_Acceleration = Vector2f{ 0,0 };
}

void Rocket::Draw() const
{
	glPushMatrix();
	glTranslatef(m_Position.x, m_Position.y, 0);
	glRotatef(m_Velocity.AngleWith(Vector2f{ 1,0 }), 0, 0, 1);

	FillRect(0, 0, 10, 50);
	glPopMatrix();
}

void Rocket::CalcFitness()
{
	float d = GetDistance(m_Position.x,m_Position.y,m_Target.x,m_Target.y);
	m_Fitness = 1.f/d;
}
