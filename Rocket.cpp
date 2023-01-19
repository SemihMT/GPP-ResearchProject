#include "Rocket.h"
Rocket::Rocket(int lifespan, float mutationRate, int& count) :
	m_Shape{423,0,50,10},
	m_Pos{423,0},
	m_Vel{},
	m_Acc{},
	m_Count{count},
	m_Lifespan{lifespan},
	m_Fitness{},
	m_Finished{},
	m_Crashed{},
	m_Dna{DNA{lifespan,mutationRate}}
{
}

Rocket::Rocket(const DNA& dna, int& count) :
	Rocket(m_Lifespan,dna.m_MutationRate, count)
	
{
	m_Dna = dna;
}

void Rocket::ApplyForce(const Vector2f& f)
{
	m_Acc += f;
}

void Rocket::Update(const Vector2f& target,const Rectf& obstacle, float elapsedSec)
{
	float distance{GetDistance(m_Pos.ToPoint2f(),target.ToPoint2f())};
	if(m_Finished == false && distance < 10.f)
	{
		m_Finished = true;
		m_CompletionTime = m_Count;
		m_Pos = target;
	}

	if(m_Pos.x > obstacle.left && m_Pos.x < obstacle.left + obstacle.width && m_Pos.y > obstacle.bottom && m_Pos.y < obstacle.bottom + obstacle.height)
	{
		m_Crashed = true;
	}


	if(m_Pos.x > 846 ||m_Pos.x < 0)
	{
		m_Crashed = true;
	}
	if(m_Pos.y > 500 ||m_Pos.y < 0)
	{
		m_Crashed = true;
	}
	if(m_Count < m_Dna.m_Genes.size())
	{
		ApplyForce(m_Dna.m_Genes[m_Count]);
	}
	if(!m_Finished && !m_Crashed)
	{
		m_Vel += m_Acc;
		m_Pos += m_Vel;
		m_Acc = Vector2f{0,0};
	}

}

void Rocket::CalcFitness(const Vector2f& target)
{
		float distance{GetDistance(m_Pos.ToPoint2f(),target.ToPoint2f())};


		// remaps the range
		m_Fitness = 1.f / (distance + 0.0000001f) ;
			//float(Range(distance, 0, 846, 846, 0));
	
		if (m_Finished) {
			m_Fitness *= powf((float)m_Dna.m_Genes.size() / (float)m_CompletionTime, 2) * 10; // completion time multiplier exponential
			
		}

		if (m_Crashed) {
			m_Fitness = 0;
		}

		m_Fitness = powf(m_Fitness, 2); // fitness becomes exponential
}

void Rocket::Draw() const
{
	glPushMatrix();
	//glTranslatef(-m_Pos.x,-m_Pos.y,0);
	glTranslatef(m_Pos.x, m_Pos.y, 0);
	float angle{atan2(m_Vel.Normalized().y,m_Vel.Normalized().x)};
	glRotatef((angle / utils::g_Pi) * 180.f, 0, 0, 1);
	

	FillRect(0, 0, 50, 10);
	glPopMatrix();
}
