#include "Synthesis.h"

bool init( SDL_Renderer* &Renderer , SDL_Window* &Window , const int SCREEN_WIDTH , const int SCREEN_HEIGHT ){

    bool success = true;
    if( SDL_Init(SDL_INIT_VIDEO)<0 ) success = false;
	else{
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ){
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		Window = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( Window == NULL ){
			success = false;
		} else{
			Renderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if(Renderer == NULL) success = false;
			else{
				SDL_SetRenderDrawColor( Renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ){
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}
void close(SDL_Renderer* Renderer , SDL_Window* Window)
{
	SDL_DestroyRenderer( Renderer );
	SDL_DestroyWindow( Window );
	Window = NULL;
	Renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool loadMedia(Texture& Background, Texture& DINO, Texture& Cactus, Texture& Play, Texture& gameOver,
               SDL_Rect DinoClips[RUNNING_ANIMATION_FRAMES],SDL_Renderer* &Renderer)
{
    bool success = true;

	if (Background.loadTexture("background.jpg",Renderer) == NULL ) success = false;

    if (Cactus.loadTexture("Cactus1.gif",Renderer) == NULL ) success = false ;

    if (DINO.loadTexture("dino.png",Renderer) == NULL ) success = false;
    else
    {
       	DinoClips[ 0 ].x =   0;
		DinoClips[ 0 ].y =   0;
		DinoClips[ 0 ].w =  123;
		DinoClips[ 0 ].h = 80;

		DinoClips[ 1 ].x =  140;
		DinoClips[ 1 ].y =   0;
		DinoClips[ 1 ].w =  128;
		DinoClips[ 1 ].h = 80;

		DinoClips[ 2 ].x = 282;
		DinoClips[ 2 ].y =   0;
		DinoClips[ 2 ].w =  145;
		DinoClips[ 2 ].h = 80;

		DinoClips[ 3 ].x = 437;
		DinoClips[ 3 ].y =   0;
		DinoClips[ 3 ].w =  128;
		DinoClips[ 3 ].h = 80;
	}

    if (Play.loadTexture("Play.png",Renderer) == NULL ) success = false;
    if (gameOver.loadTexture("GameOver.jpg", Renderer) ==NULL ) success = false;
    return success;
}
void RENDER(Texture& Background, Texture& DINO, Texture& Cactus, Texture& Play,Texture& gameOver, Dino& Dinosaur, Obstacle& Cactus1,Obstacle& Cactus2,
               SDL_Rect DinoClips[RUNNING_ANIMATION_FRAMES],int& scrollingOffset, int& frame, SDL_Renderer* &Renderer,bool &press)
{
    if(press==false){
        scrollingOffset-=3;

        if( scrollingOffset < -Background.getWidth() )
        {
            scrollingOffset = 0;
        }
    }

    Background.render( scrollingOffset, 0,Renderer,NULL );
    Background.render( scrollingOffset + Background.getWidth(), 0 ,Renderer,NULL );

    Play.render( ( SCREEN_WIDTH-Play.getWidth() )/2 ,( SCREEN_HEIGHT-Play.getHeight() ) /2 , Renderer,NULL );

    Cactus1.Render( Cactus,Renderer );
    Cactus2.Render( Cactus,Renderer );

    Dinosaur.Render( DINO,Renderer,DinoClips,frame );

    if(press==true){
        gameOver.render( ( SCREEN_WIDTH-gameOver.getWidth() )/2 ,( SCREEN_HEIGHT-gameOver.getHeight() ) /2 , Renderer,NULL );
    }

}
