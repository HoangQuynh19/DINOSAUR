#ifndef BARRIER_H_
#define BARRIER_H_

#include "loadTexture.h"

class Barrier
{
private:
    int PosX, PosY;
    int VelX;
    int VELX_C;

public:
    Barrier(int x,int y);
    const int WIDTH=80;

    void handleEvent(LTexture& gPlay, SDL_Event&e );

    void move(LTexture& Texture);


    void Render(LTexture& Texture,SDL_Renderer* gRenderer);

    int getPosX();
    int getPosy();
    void End(int x);
};



#endif // BARRIER_H_
