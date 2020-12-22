#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "vec2d.h"

int main(int argc, char **argv) {
	 if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	 	SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Quit();

	return 0;
}
