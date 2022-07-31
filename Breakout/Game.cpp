#include "Game.h"

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{

}

void Game::Init()
{

}

void Game::Update(float dt)
{

}

void Game::ProcessInput(float dt)
{

}

void Game::Render()
{

}

void Game::StartGameLoop()
{
	do {
		SDL_GetMouseState(&mouse_x, &mouse_y);
		// Event handling
		while (SDL_PollEvent(&e)) {

			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE: {
					quit = true;
					break;
				}
				//case SDLK_w: {
				//	break;
				//}
				case SDLK_a: {
					break;
				}
				//case SDLK_s: {
				//	break;
				//}
				case SDLK_d: {
					break;
				}
				default: {
					break;
				}
				}
			}
			if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
				//case SDLK_w: {
				//	break;
				//}
				case SDLK_a: {
					break;
				}
				//case SDLK_s: {
				//	break;
				//}
				case SDLK_d: {
					break;
				}
				default: {
					break;
				}
				}
			}
		}

		// Scene showing
		SDL_RenderClear(renderer);

	} while (state == STATE_OK);          // play while the snake is alive
}
