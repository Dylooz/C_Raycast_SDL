#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#include "bool.h"
#include "vec2d.h"

#define WINDOW_TITLE "Raycasting in C with SDL"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int init(SDL_Window *window, SDL_Surface *surface);
int mainLoop(SDL_Window *window, SDL_Surface *surface);

void endall(SDL_Window *window, SDL_Surface *surface);

int main(int argc, char **argv) {
	
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;

	int err;

	if ((err = init(window, surface)) != 0) return err; 

	if ((err = mainLoop(window, surface)) != 0) return err;

    endall(window, surface);

	return 0;

}


int init(SDL_Window *window, SDL_Surface *surface) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	 	SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    } else {
    	if ((window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL) {
    		SDL_Log("Unable to create Window: %s\n", SDL_GetError());
    		SDL_Quit();
    		return 2;
    	} else {
    		if ((surface = SDL_GetWindowSurface(window)) == NULL) {
    			SDL_Log("Unable to fetch Window Surface: %s\n", SDL_GetError());
    			SDL_DestroyWindow(window);
    			SDL_Quit();
    			return 3;
    		}
    	}
    	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    	SDL_UpdateWindowSurface(window);
    }
    return 0;
}


int mainLoop(SDL_Window *window, SDL_Surface *surface) {
	bool quit = FALSE;
	printf("%d\n", SDL_QUIT);

	while (!quit) {
		
		SDL_Event *e;
		while (SDL_PollEvent(e) != 0) {
			switch (e->type) {
				case SDL_QUIT:
					quit = TRUE;
					break;
				default:
					break;
			}
			SDL_Delay(20);
		}

		if (quit) break;

	}

	return 0;

}


void endall(SDL_Window *window, SDL_Surface *surface) {
	
	SDL_DestroyWindow(window);
	window = NULL;
	
	surface = NULL;

	SDL_Quit();
}