#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#include "vec2d.h"

#define SCREEN_TITLE "Raycasting in C with SDL"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int main(int argc, char **argv) {

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	 	SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    } else if (SDL_WasInit(SDL_INIT_EVERYTHING) == 0) {
    	if ((window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL) {
    		SDL_Log("Unable to create SDL_Window: %s", SDL_GetError());
    		return 2;
    	}
    	sleep(5);
    }

    SDL_Quit();

	return 0;
}
