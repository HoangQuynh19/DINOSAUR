#include "Dino.h"

Dino::Dino()
{
    PosX=POSX_BEGIN_DINO;
    PosY=POSY_BEGIN_DINO;
    Altitude=0;
    Gravity=0;
}
void Dino::handleEvent(SDL_Event& e, bool& press)
{
    press=false;
    if( press==false ){
        if( e.type == SDL_KEYDOWN &&PosY==POSY_BEGIN_DINO )
        {
            switch( e.key.keysym.sym )
            {
                case SDLK_SPACE:
                    {
                        Altitude=HEIGHT;
                        Gravity=GLAVITY;
                        break;
                    }
            }
        }
    }

}
void Dino::jump(int &frame)
{

    PosY-=Altitude;
    Altitude-=Gravity;

    if(PosY>=POSY_BEGIN_DINO)
    {
        Gravity=0;
        Altitude=0;
    }
    else  frame=0;
}
void Dino::Render(Texture& Dino, SDL_Renderer* Renderer, SDL_Rect SpriteClips[4], int& frame)
{
    SDL_Rect* currentClip = &SpriteClips[frame/4];

    Dino.render( PosX, PosY, Renderer, currentClip );

}

int Dino::getPosX()
{
    return PosX;
}
int Dino::getPosy()
{
    return PosY;
}
void Dino::End(int y)
{
    PosY=POSY_BEGIN_DINO;
    Altitude=0;
    Gravity=0;
}

