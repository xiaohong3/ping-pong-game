#include <iostream>
#include <SDL2/SDL.h>
#include "Peddle.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int PEDDLE_WIDTH = 30;
const int PEDDLE_HEIGHT = SCREEN_HEIGHT / 4;
const int PEDDLE_LEFT_X = 0;
const int PEDDLE_RIGHT_X = SCREEN_WIDTH - PEDDLE_WIDTH;
const int PEDDLE_INIT_Y = SCREEN_HEIGHT / 4;

SDL_Rect peddleLeft = {PEDDLE_LEFT_X, PEDDLE_INIT_Y, PEDDLE_WIDTH, PEDDLE_HEIGHT};
SDL_Rect peddleRight= {PEDDLE_RIGHT_X, PEDDLE_INIT_Y, PEDDLE_WIDTH, PEDDLE_HEIGHT};

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

void render()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gRenderer);

    // Peddle peddle_left(0, SCREEN_HEIGHT / 4, 30, SCREEN_HEIGHT / 2);

    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(gRenderer, &peddleLeft);

    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderFillRect(gRenderer, &peddleRight);

    SDL_RenderPresent(gRenderer);
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
                else if (e.type == SDL_KEYDOWN)
                {
                    switch (e.key.keysym.sym)
                    {
                        case SDLK_UP:
                            peddleRight.y -= 4;
                            break;
                        case SDLK_DOWN:
                            peddleRight.y += 4;
                        case SDLK_w:
                            peddleLeft.y -= 4;
                            break;
                        case SDLK_s:
                            peddleLeft.y += 4;
                            break;
                    }
                }

            }

            render();
        }
    }

    close();

    return 0;
}
