#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#include "vec2d.h"

#define WINDOW_TITLE "Raycasting in C with SDL"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(int argc, char **argv) {

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	 	SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    } else {
    	if ((window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL) {
    		SDL_Log("Unable to create Window: %s", SDL_GetError());
    		SDL_Quit();
    		return 2;
    	} else {
    		if ((screenSurface = SDL_GetWindowSurface(window)) == NULL) {
    			SDL_Log("Unable to fetch Window Surface: %s", SDL_GetError());
    			SDL_DestroyWindow(window);
    			SDL_Quit();
    			return 3;
    		}
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);

            SDL_Delay(5000);

    	}
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

	return 0;
}
