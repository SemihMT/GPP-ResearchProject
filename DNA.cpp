#include "DNA.h"
DNA::DNA(int lifespan, float mutationRate):
	m_Genes{},
	m_Magnitude{.2f},
	m_MutationRate{mutationRate}
	
{
	for(int i{}; i < lifespan; ++i)
	{
		m_Genes.push_back(RandomVector(m_Magnitude));
	}
}

DNA::DNA(std::vector<Vector2f>& genes, float mutationRate):
	m_Genes{genes},
	m_Magnitude{.2f},
	m_MutationRate{mutationRate}
{
}

DNA DNA::Crossover(DNA partner)
{
	std::vector<Vector2f> newGenes;
	for(int i{}; i < m_Genes.size(); ++i)
	{
		int midPoint{int(RandomNumber(float(m_Genes.size())))};
		if(i > midPoint)
		{
			newGenes.push_back(m_Genes[i]);
		}else
		{
			newGenes.push_back(partner.m_Genes[i]);
		}
	}
	return DNA(newGenes,m_MutationRate);
}

void DNA::Mutate()
{
	for(int i{}; i < m_Genes.size(); ++i)
	{
		if(RandomNumber(0.0f,1.0f) < m_MutationRate)
		{
			m_Genes[i] = RandomVector(m_Magnitude);
		}
	}
}
