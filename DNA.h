#pragma once
#include "pch.h"
#include <vector>
#include "utils.h"
#include "UtilityFunctions.h"
using namespace utils;
struct DNA
{
	DNA();
	DNA(int lifespan, float mutationRate);
	DNA(std::vector<Vector2f>& genes, float mutationRate);
	
	DNA Crossover(DNA partner);
	void Mutate();
	
	std::vector<Vector2f> m_Genes;
	float m_Magnitude{0.2f};
	float m_MutationRate;
};
