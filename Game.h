#pragma once
#include "Texture.h"
#include "Rocket.h"
#include "RocketPopulation.h"
#include <memory>
class Population;
class Game final
{
public:
	explicit Game(const Window& window);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game(Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	~Game();

	void Update(float elapsedSec);
	void Draw() const;

	// Event handling
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);
	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e);
	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e);
	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e);

private:
	// DATA MEMBERS
	const Window m_Window;
	Texture* m_pText;
	std::unique_ptr<Texture> m_upToBe;
	std::unique_ptr<Texture> m_upGenerations;
	std::unique_ptr<Texture> m_upMutationRate;
	std::unique_ptr<Texture> m_upPopSize;

	std::unique_ptr<Rocket> m_Rocket;
	std::unique_ptr<RocketPopulation> m_RocketPop;
	int m_RocketLifeSpan;
	int m_Counter{};
	Point2f m_Target{};


	std::string m_TargetPhrase;
	int m_PopMax;
	float m_MutationRate;
	std::unique_ptr<Population> m_Population;

	std::string m_BestPhrase;
	std::string m_AllPhrases;


	// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;
	void setup();
	void displayInfo();
};