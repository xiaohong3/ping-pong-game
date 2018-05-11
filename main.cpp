#include <iostream>
#include <SDL2/SDL.h>
#include "Peddle.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_Renderer* gRenderer = nullptr;

void close()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(window);
    gRenderer = nullptr;
    window = nullptr;
    SDL_Quit();
}

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if( window == nullptr )
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == nullptr)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
        }
    }
    return success;
}

int main()
{
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        bool quit = false;
        SDL_Event e;

        while(!quit)
        {
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }

//                SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
//                SDL_RenderClear(gRenderer);
//
//                Peddle peddle_left(0, SCREEN_HEIGHT / 4, 30, SCREEN_HEIGHT / 2);
//                SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
//                SDL_RenderFillRect(gRenderer, &peddle_left.getGeometry());
//
//                SDL_RenderPresent(gRenderer);
            }
        }
    }

    close();

    return 0;
}
