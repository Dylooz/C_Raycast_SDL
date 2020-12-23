#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <unistd.h>

#include "bool.h"
#include "vec2d.h"

#define WINDOW_TITLE "Raycasting in C with SDL"
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 400
#define FRAMERATE 30

typedef struct {
	Vector2d *start;
	Vector2d *end;
} Wall;

int init(SDL_Window **window, SDL_Surface **surface);
int mainLoop(SDL_Window *window, SDL_Surface *surface);

void cleanup(SDL_Window *window, SDL_Surface *surface);

void drawScreen(SDL_Surface *surface, int x, int y, int w, int h, uint8_t colour);

Wall **readWallFile(char *filename);

int main(int argc, char **argv) {

	//PREVENTS SEGFAULT SOMEHOW
	Wall *w1 = malloc(sizeof(Wall));
	w1->start = vector_create(0,0);
	free(w1->start);
	free(w1);

	//READ MAP FILE AND BUILD ARRAY
	Wall **walls = readWallFile("1.map");
	if (walls == NULL) {
		printf("Unable to read mapfile.\n");
		return 1;
	}
	for (Wall **w = walls; *w; w++) {
		printf("\nstartx %F\nstarty %F\nendx %F\nendy %F\n", (*w)->start->x, (*w)->start->y, (*w)->end->x, (*w)->end->y);
	}
	
	//DECLARE VARIABLES
	SDL_Window *window = NULL;
	SDL_Surface *surface = NULL;

	int err;

	//RUN INIT FUNCTION
	if ((err = init(&window, &surface)) != 0) return err;

	//RUN THE MAINLOOP
	err = mainLoop(window, surface);

	//CLEAN UP
    cleanup(window, surface);


    //ERR != 0 ON ERROR
	return err;

}

int init(SDL_Window **window, SDL_Surface **surface) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	 	SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        return -1;
    } else {
    	if ((*window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL) {
    		SDL_Log("Unable to create Window: %s\n", SDL_GetError());
    		SDL_Quit();
    		return -2;
    	} else {
    		if ((*surface = SDL_GetWindowSurface(*window)) == NULL) {
    			SDL_Log("Unable to fetch Window Surface: %s\n", SDL_GetError());
    			SDL_DestroyWindow(*window);
    			SDL_Quit();
    			return -3;
    		}
    	}    	
    }
    return 0;
}


int mainLoop(SDL_Window *window, SDL_Surface *surface) {

	Wall **walls;

	bool quit = FALSE;

	while (!quit) {
		SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
		
		// DISPATCH EVENTS
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
				case SDL_QUIT:
					quit = TRUE;
					break;
				default:
					break;
			}
		}

		if (quit) break;

		//PROCESS STATE

		//UPDATE SCREEN
		drawScreen(surface, 0, 0, 50, 50, 128);
    	SDL_UpdateWindowSurface(window);
    	SDL_Delay(1 / FRAMERATE);

	}

	return 0;

}


void cleanup(SDL_Window *window, SDL_Surface *surface) {
	
	SDL_DestroyWindow(window);
	window = NULL;
	
	surface = NULL;

	SDL_Quit();
}

void drawScreen(SDL_Surface *surface, int x, int y, int w, int h, uint8_t colour) {
	SDL_Rect r = { .x = x, .y = y, .w = w, .h = h };
	SDL_FillRect(surface, &r, SDL_MapRGB(surface->format, colour, colour, colour));
}

Wall **readWallFile(char *filename) {
	FILE *fp = fopen(filename, "r");

	if (fp == NULL) {
		return NULL;
	}

	char *line = NULL;
    size_t len = 0;
    ssize_t read;

    Wall **walls;
    int numwalls = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
    	Wall *wall = malloc(sizeof(Wall));
    	if (wall == NULL) return NULL;
    	
    	if ((wall->start = vector_create(0, 0)) == NULL) return NULL;
    	if ((wall->end = vector_create(0, 0)) == NULL) return NULL;
    	
    	char *cur = NULL;
    	int len = 0;
    	int count = 0;
    	
    	for (char *c = line; (*c != '\0' && *c != '\n'); c++) {
    		
    		len++;

    		if ((cur = (char *)realloc(cur, len * sizeof(char))) == NULL) return NULL;
    		
    		if (*c == ' ') {
    			cur[len - 1] = '\0';
    			int val = atoi(cur);
    			switch(count) {
    				case 0:
    					wall->start->x = val;
    					break;
    				case 1:
    					wall->start->y = val;
    					break;
    				case 2:
    					wall->end->x = val;
    					break;
    				default:
    					printf("Fix your code (Count = %d)\n", count);
    			}
    			
    			len = 0;
    			free(cur);
    			cur = NULL;
    			
    			count++;
    		
    		} else {
    		
    			cur[len - 1] = *c;
    		
    		}
    	}
    	
    	if ((cur = (char *)realloc(cur, (len + 1) * sizeof(char))) == NULL) return NULL;
    	
    	cur[len] = '\0';
   		
   		wall->end->y = atoi(cur);
   		
   		numwalls++;
   		
   		walls = (Wall **)realloc(walls, sizeof (Wall *) * numwalls);
   		walls[numwalls - 1] = wall;

    	free(cur);
    	
    }

    if ((walls = (Wall **)realloc(walls, sizeof (Wall *) * (numwalls + 1))) == NULL) return NULL;
    walls[numwalls] = NULL;

    fclose(fp);
    fp = NULL;

    free(line);
    line = NULL;

    return walls;
}