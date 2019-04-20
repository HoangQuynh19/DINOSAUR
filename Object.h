#ifndef OBJECT_H_
#define OBJECT_H_

#include "loadTexture.h"

#define J_HEIGHT 20
#define J_GLAVITY 1

class Dino
{
private:
    int PosX,PosY;
    int altitude;
    int gravity;
public:
    static const int POSX_BEGIN_DINO = 120;
    static const int POSY_BEGIN_DINO = 345;
    Dino();
    void handleEvent( SDL_Event&e,bool& press );

    void jump();

    void Render(LTexture& gDino,SDL_Renderer* gRenderer,SDL_Rect gSpriteClips[4],int & frame);

    int getPosX();
    int getPosy();
    void End(int y);

};

#endif // OBJECT_H
