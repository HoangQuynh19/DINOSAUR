#include "GameOver.h"

bool GameOver(SDL_Event&e,Dino& Dino, Barrier& Cactus1,Barrier& Cactus2,
               SDL_Renderer* gRenderer,LTexture& gameOver)
{
    bool end=false;
   // bool PlayAgain=true;
    int distance_left1_c = Cactus1.getPosX()-Dino.getPosX();
    int distance_right1_c = Dino.getPosX()- Cactus1.getPosX();

    int distance_left2_c = Cactus2.getPosX()-Dino.getPosX();
    int distance_right2_c = Dino.getPosX()- Cactus2.getPosX();


    if( distance_left1_c <= limit_left_C && Dino.getPosy() > limit_above_C && Cactus1.getPosX()> Dino.getPosX())
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();


        Dino.End(y);
        Cactus1.End(x);
        Cactus2.End(x+distanceCactus);



        end=true;
    }


    if ( distance_right1_c <= limit_right_C && Dino.getPosy() > limit_above_C && Cactus1.getPosX()< Dino.getPosX() )
    {
        int x=Cactus1.getPosX();
        int y=Dino.getPosy();



        Cactus1.End(x);
        Cactus2.End(x+distanceCactus);
        Dino.End(y);
        end=true;
    }


    if( distance_left2_c <= limit_left_C && Dino.getPosy() > limit_above_C && Cactus2.getPosX()> Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();

        Cactus2.End(x);
        Cactus1.End(x-distanceCactus);
        Dino.End(y);

         end=true;
    }

    if ( distance_right2_c <= limit_right_C && Dino.getPosy() > limit_above_C && Cactus2.getPosX()< Dino.getPosX())
    {
        int x=Cactus2.getPosX();
        int y=Dino.getPosy();




        Cactus2.End(x);
        Cactus1.End(x-SCREEN_WIDTH/2);
        Dino.End(y);

        end=true;
    }

    if (end == true)
    {
    gameOver.loadTexture("GameOver.jpg",gRenderer);
    gameOver.render( ( SCREEN_WIDTH-gameOver.getWidth() )/2 ,( SCREEN_HEIGHT-gameOver.getHeight() ) /2 , gRenderer,NULL );

  /*  if( e.type == SDL_KEYDOWN  )
        {
            switch( e.key.keysym.sym )
            {
                case SDLK_y:
                    {
                        PlayAgain=true;
                        break;
                    }
                case SDLK_n:
                    {
                        PlayAgain=false;
                        break;
                    }
            }
        }*/
    }
    else gameOver.free();
    return end;
}

