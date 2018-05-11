#include "Peddle.h"
SDL_Rect* Peddle::getGeometry()
{
    return &geometry;
}

Peddle::Peddle(int x, int y, int w, int h)
{
    geometry = {}
}

Peddle::~Peddle()
{
    //dtor
}
