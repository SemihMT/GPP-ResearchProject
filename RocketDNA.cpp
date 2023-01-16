#include "pch.h"
#include "RocketDNA.h"

RocketDNA::RocketDNA():
	m_Genes{}
{

	for(int i{}; i < 100; ++i)
	{
		m_Genes.push_back(Vector2f{utils::RandomFloat(),utils::RandomFloat()});
	}
}

RocketDNA::RocketDNA(std::vector<Vector2f> dna)
{
	m_Genes = dna;
}

std::vector<Vector2f> RocketDNA::CrossOver(RocketDNA* partner)
{
	std::vector<Vector2f> newDna{};
	newDna.resize(m_Genes.size());
	int midPoint{utils::RandomInteger(0,int(m_Genes.size()-1))};
	for(int i{}; i < m_Genes.size(); ++i)
	{
		if(i>0)
		{
			newDna[i] = m_Genes[i];
		}else
		{
			newDna[i] = partner->GetGenes()[i];
		}
	}
	return newDna;
}
