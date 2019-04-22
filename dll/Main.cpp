#include "Dino.h"
#include "Obstacle.h"
#include "Synthesis.h"
#include "Texture.h"
#include "GameOver.h"

int main(int argc, char* args[])
{
    SDL_Renderer* Renderer=NULL;
    SDL_Window* Window=NULL;

    Texture Background;
    Texture DINO;
    Texture Cactus;
    Texture Play;
    Texture gameOver;

    int Running_Animation_Frames=4;
    SDL_Rect DinoClips[ Running_Animation_Frames ];

    bool quit=false;

    int POSY_BEGIN_CACTUS = 300;

    if( !init(Renderer,Window,SCREEN_WIDTH,SCREEN_HEIGHT) ) return -1;

    SDL_Event e;

   // while(!PlayAgain)
   // {
        if( !loadMedia( Background, DINO, Cactus, Play, gameOver, DinoClips, Renderer ) ) return -1;

        Dino Dinosaur;

        Obstacle Cactus1(SCREEN_WIDTH,POSY_BEGIN_CACTUS);
        Obstacle Cactus2(SCREEN_WIDTH+SCREEN_WIDTH/2,POSY_BEGIN_CACTUS);

        int scrollingOffset = 0;
        int frame = 0;
        bool press=false;
        while(!quit)
        {

            while(SDL_PollEvent(&e)!=0)
            {
                if( e.type == SDL_QUIT ) quit = true;

                if( e.type == SDL_KEYDOWN )
                {
                    switch( e.key.keysym.sym )
                    {
                        case SDLK_p:{ Play.free();break;}
                       // case SDLK_y:{PlayAgain=true;break;}
                       // case SDLK_n:{PlayAgain=false;quit=true;}

                    }
                }
                Cactus1.handleEvent(e);
                Cactus2.handleEvent(e);



                Dinosaur.handleEvent(e,press);
            }
            Cactus1.move(Cactus);
            Cactus2.move(Cactus);

            Dinosaur.jump(frame);

            SDL_RenderClear( Renderer );

            press=GameOver(e, Dinosaur,Cactus1,Cactus2,Renderer,gameOver);

            RENDER(Background, DINO, Cactus, Play,gameOver, Dinosaur,Cactus1, Cactus2, DinoClips, scrollingOffset, frame,Renderer,press);
            //Update Screen
            SDL_RenderPresent( Renderer );
            //
            if(press==false){
                ++frame;
                if( frame / Running_Animation_Frames >= Running_Animation_Frames )
                {
                    frame = 0;
                }
            }

        }
   // }


    Background.free();
    DINO.free();
    Cactus.free();
    Play.free();
    gameOver.free();

    close(Renderer,Window);
    return 0;
}


