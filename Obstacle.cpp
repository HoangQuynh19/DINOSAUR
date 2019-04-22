#include "Obstacle.h"

Obstacle::Obstacle(int x,int y)
{
    PosX = x;
    PosY = y;

    VelX = 0;
    VELX_C=6;

}

void Obstacle::handleEvent( SDL_Event& e)
{
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_p:
            {
            VelX -= VELX_C;
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

void Obstacle::move(Texture& Texture)
{
    PosX+=VelX;
    if( PosX < 0-WIDTH )
    {
        PosX =WIDTH+ (PosX + SCREEN_WIDTH + VelX) % SCREEN_WIDTH;
    }

}
void Obstacle::Render(Texture& Texture,SDL_Renderer* Renderer)
{

   Texture.render(PosX,PosY,Renderer,NULL);
 //  Play.render((SCREEN_WIDTH-Play.getWidth())/2, (SCREEN_HEIGHT-Play.getHeight())/2,Renderer,NULL);
}
int Obstacle::getPosX()
{
    return PosX;
}
int Obstacle::getPosy()
{
    return PosY;
}
void Obstacle::End(int x)
{
    PosX=x;
    VelX=0;
}

