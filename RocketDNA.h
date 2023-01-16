#pragma once
#include "utils.h"
#include <vector>
class RocketDNA
{
public:
	RocketDNA();
	RocketDNA(std::vector<Vector2f> dna);
	std::vector<Vector2f> GetGenes() {return m_Genes;}
	std::vector<Vector2f> CrossOver(RocketDNA* partner);
private:
	std::vector<Vector2f> m_Genes;
	

};
