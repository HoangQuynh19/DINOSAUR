#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "loadTexture.h"
#include "Object.h"
#include "Barrier.h"


#define limit_left_C 115
#define limit_right_C 50
#define limit_above_C 290


#define distanceCactus 550
bool GameOver(SDL_Event&e,Dino& Dino, Barrier & Cactus1,Barrier & Cactus2
               ,SDL_Renderer*gRenderer,LTexture& gameOver );

#endif // GAMEOVER_H_

