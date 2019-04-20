#include "Barrier.h"

Barrier::Barrier(int x,int y)
{
    PosX = x;
    PosY = y;

    VelX = 0;
    VELX_C=5;
}

void Barrier::handleEvent(LTexture& gPlay,SDL_Event& e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_p:
            {
            VelX -= VELX_C;
            gPlay.free();
            break;
            }
        }
    }
    if(e.type == SDL_KEYDOWN && e.key.repeat >= 0)
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_p:
            {
             VELX_C=0;
            break;
            }
        }
    }
}

void Barrier::move(LTexture& Texture)
{
    PosX+=VelX;
    if( PosX < 0-WIDTH )
    {
        PosX =WIDTH+ (PosX + SCREEN_WIDTH + VelX) % SCREEN_WIDTH;
    }

}
void Barrier::Render(LTexture& Texture,SDL_Renderer* gRenderer)
{
   Texture.render(PosX,PosY,gRenderer,NULL);
}
int Barrier::getPosX()
{
    return PosX;
}
int Barrier::getPosy()
{
    return PosY;
}
void Barrier::End(int x)
{
    PosX=x;
    VelX=0;
}

