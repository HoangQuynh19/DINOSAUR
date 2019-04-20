#include "Object.h"
#include "Barrier.h"
#include "GameOver.h"

SDL_Renderer* gRenderer=NULL;
SDL_Window* gWindow=NULL;

const char WINDOW_TITLE[]="DINOSAUR";

const int POSY_BEGIN_CACTUS = 300;

LTexture gBackground;
LTexture gDino;
LTexture gCactus;

LTexture gPlay;
LTexture gameOver;

Dino Dino;
#define PosX_Cactus2 1550


Barrier Cactus1(SCREEN_WIDTH,POSY_BEGIN_CACTUS);
Barrier Cactus2(PosX_Cactus2,POSY_BEGIN_CACTUS);



const int RUNNING_ANIMATION_FRAMES = 4;
SDL_Rect gDinoClips[ RUNNING_ANIMATION_FRAMES ];

bool init();
void close();

bool loadMedia()
{
	bool success = true;

	if (gBackground.loadTexture("background.jpg",gRenderer) == NULL ) success = false;

    if (gCactus.loadTexture("barrier1.gif",gRenderer) == NULL ) success = false ;

    if (gDino.loadTexture("dino.png",gRenderer) == NULL ) success = false;
    else
    {
       //Set sprite clips
		gDinoClips[ 0 ].x =   0;
		gDinoClips[ 0 ].y =   0;
		gDinoClips[ 0 ].w =  123;
		gDinoClips[ 0 ].h = 80;

		gDinoClips[ 1 ].x =  140;
		gDinoClips[ 1 ].y =   0;
		gDinoClips[ 1 ].w =  128;
		gDinoClips[ 1 ].h = 80;

		gDinoClips[ 2 ].x = 282;
		gDinoClips[ 2 ].y =   0;
		gDinoClips[ 2 ].w =  145;
		gDinoClips[ 2 ].h = 80;

		gDinoClips[ 3 ].x = 437;
		gDinoClips[ 3 ].y =   0;
		gDinoClips[ 3 ].w =  128;
		gDinoClips[ 3 ].h = 80;
	}

    if (gPlay.loadTexture("Play.png",gRenderer) == NULL ) success = false;


	return success;
}

void Render(int& scrollingOffset,int& frame)
{
    --scrollingOffset;
    if( scrollingOffset < -gBackground.getWidth() )
    {
        scrollingOffset = 0;
    }

    gBackground.render( scrollingOffset, 0,gRenderer,NULL );
    gBackground.render( scrollingOffset + gBackground.getWidth(), 0 ,gRenderer,NULL );

    gPlay.render( ( SCREEN_WIDTH-gPlay.getWidth() )/2 ,( SCREEN_HEIGHT-gPlay.getHeight() ) /2 , gRenderer,NULL );



    Cactus1.Render( gCactus,gRenderer );
    Cactus2.Render( gCactus,gRenderer );

    Dino.Render( gDino,gRenderer,gDinoClips,frame );


}

int main(int argc, char* args[])
{
    if( !init() ) return -1;

  //  bool PlayAgain = true;

 //   while(PlayAgain)
  //  {
        if( !loadMedia() ) return -1;

        SDL_Event e;
        bool quit=false;

        int scrollingOffset = 0;
        int frame = 0;

        while(!quit)
        {
            bool press=false;
            while(SDL_PollEvent(&e)!=0)
            {
                if( e.type == SDL_QUIT )
                {
                    quit = true;

                }
                Cactus1.handleEvent(gPlay,e);
                Cactus2.handleEvent(gPlay,e);

                press=GameOver(e,Dino, Cactus1,Cactus2,gRenderer,gameOver);

                Dino.handleEvent(e,press);
            }
            Cactus1.move(gCactus);
            Cactus2.move(gCactus);

            Dino.jump();

            SDL_RenderClear( gRenderer );

            Render(scrollingOffset,frame);

            /*PlayAgain=*/GameOver(e,Dino, Cactus1,Cactus2,gRenderer,gameOver);

            SDL_RenderPresent( gRenderer );

            ++frame;

                    if( frame / 4 >= RUNNING_ANIMATION_FRAMES )
                    {
                        frame = 0;
                    }

        }
   // }

    close();
    return 0;
}

bool init(){
    bool success = true;
    if( SDL_Init(SDL_INIT_VIDEO)<0 ) success = false;
	else{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		gWindow = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL ){
			success = false;
		} else{
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if(gRenderer == NULL) success = false;
			else{
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
					success = false;
				}
			}
		}
	}

	return success;
}
void close()
{
    gBackground.free();
    gDino.free();
    gCactus.free();
    gPlay.free();

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
