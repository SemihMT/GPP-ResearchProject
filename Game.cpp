#include "pch.h"
#include "Game.h"

#include <iostream>


Game::Game( const Window& window ) 
	:m_Window{ window },
	m_Generations{},
	m_Frames{},
	m_PopulationSize{},
	m_Lifespan{},
	m_MutationRate{},
	m_Target{600,350}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{

	m_PopulationSize = 600;
	m_Lifespan = 400;
	m_MutationRate = 0.05f;
	m_Population = new Population{m_PopulationSize, m_Lifespan, m_MutationRate, m_Target, Rectf{200,250,500,20},m_Frames};
}

void Game::Cleanup( )
{
	delete m_Population;
}

void Game::Update( float elapsedSec )
{
	m_Population->Update(elapsedSec);
	++m_Frames;
	if(m_Frames == m_Lifespan)
	{
		m_MaxFitness = m_Population->NaturalSelection();
		std::cout << "Generation: " << m_Generations<<"\n";
		std::cout << (float(m_Population->GetFinished()) / float(m_PopulationSize)) * 100.0f << " % Completed\n";
		std::cout << "Max Fitness: "<< m_MaxFitness << "\n";
		m_Population->Selection();
		m_Frames = 0;
		++m_Generations;
	}
	

	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawEllipse(m_Target.ToPoint2f(),5,5);
	DrawRect(Rectf{200,250,500,20});
	m_Population->Draw();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//m_Target = Vector2f{float(e.x),float(e.y)};
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
