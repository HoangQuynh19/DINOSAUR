#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include "Texture.h"

class Obstacle
{
private:
    int PosX, PosY;
    int VelX;
    int VELX_C;

public:
    Obstacle(int x,int y);

    const int WIDTH=80;

    void handleEvent( SDL_Event&e );

    void move(Texture& Texture);

    void Render(Texture& Texture,SDL_Renderer* Renderer);

    int getPosX();
    int getPosy();
    void End(int x);
};
#endif // OBSTACLE_H_

