#ifndef PEDDLE_H
#define PEDDLE_H
#include <SDL2/SDL.h>

class Peddle
{
    public:
        Peddle(int x, int y, int w, int h);
        // Peddle(SDL_Rect rect): geometry(rect) {};
        SDL_Rect* getGeometry();
        virtual ~Peddle();

    private:
        SDL_Rect* geometry;

};

#endif // PEDDLE_H
