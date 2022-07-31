// Breakout.cpp : Defines the entry point for the application.
//

#include "Breakout.h"

using namespace std;

int main()
{
	int SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080, MAP_WIDTH = 600, MAP_HEIGHT = 600;

	int top_border_Y = (SCREEN_HEIGHT / 2) - (MAP_HEIGHT / 2);
	int left_border_X = (SCREEN_WIDTH / 2) - (MAP_WIDTH / 2);
	int bottom_border_Y = (SCREEN_HEIGHT / 2) + (MAP_HEIGHT / 2);
	int right_border_X = (SCREEN_WIDTH / 2) + (MAP_WIDTH / 2);

	int border[4] = { top_border_Y, left_border_X, bottom_border_Y, right_border_X };

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow("big_asteroids", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<int> uid1(left_border_X, right_border_X);
	std::uniform_int_distribution<int> uid2(top_border_Y, bottom_border_Y);

	std::uniform_int_distribution<int> uid3(-5, 5);
	std::uniform_int_distribution<int> uid4(-5, 5);

	SDL_Event e;

	while (!quit) {
		SDL_GetMouseState(&mouse_x, &mouse_y);
		// Event handling
		while (SDL_PollEvent(&e)) {

			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE: {
					quit = true;
					break;
				}
				case SDLK_w: {
					MoveUp = true;
					break;
				}
				case SDLK_a: {
					MoveLeft = true;
					break;
				}
				case SDLK_s: {
					MoveDown = true;
					break;
				}
				case SDLK_d: {
					MoveRight = true;
					break;
				}
				default: {
					break;
				}
				}
			}
			if (e.type == SDL_KEYUP) {
				switch (e.key.keysym.sym) {
				case SDLK_w: {
					MoveUp = false;
					speed_up = 4;
					break;
				}
				case SDLK_a: {
					MoveLeft = false;
					speed_left = 4;
					break;
				}
				case SDLK_s: {
					MoveDown = false;
					speed_down = 4;
					break;
				}
				case SDLK_d: {
					MoveRight = false;
					speed_right = 4;
					break;
				}
				default: {
					break;
				}
				}
			}

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (e.button.button == SDL_BUTTON_LEFT) {
					if (is_shot_allowed) {
						bullet = new Sprite(renderer, "../data/bullet.png", spaceship->GetX() + 10, spaceship->GetY() + 10, mouse_x, mouse_y, 20, 20, border);
					}
				}
			}
		}

		// Scene showing
		SDL_RenderClear(renderer);

		background->Draw();

		if (spaceship == NULL) {
			if ((SDL_GetTicks() - StartTick) >= 1000) {
				spaceship = new Sprite(renderer, "../data/spaceship.png", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0, 30, 30, border);
				is_shot_allowed = true;
			}
		}
		else {

			spaceship->Draw();

			if (bullet != NULL) {
				bullet->Motion();
				bullet->Draw();
			}
		}

		SDL_RenderPresent(renderer);
	}

	cout << "Hello CMake." << endl;
	return 0;
}
