#ifndef DINO_H_
#define DINO_H_

#include "Texture.h"

#define HEIGHT 20
#define GLAVITY 1

class Dino
{
private:
    int PosX,PosY;
    int Altitude;
    int Gravity;
public:
    static const int POSX_BEGIN_DINO = 120;
    static const int POSY_BEGIN_DINO = 345;
    Dino();
    void handleEvent( SDL_Event&e, bool& press );

    void jump(int &frame);

    void Render(Texture& Dino, SDL_Renderer* Renderer, SDL_Rect SpriteClips[4], int& frame);

    int getPosX();
    int getPosy();
    void End(int y);
};

#endif // DINO_H

