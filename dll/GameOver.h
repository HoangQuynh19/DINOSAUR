#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "Texture.h"
#include "Obstacle.h"
#include "Dino.h"

#define Lim_left 112
#define Lim_right 50
#define Lim_above 290

bool GameOver(SDL_Event&e, Dino& Dino, Obstacle & Cactus1,Obstacle & Cactus2,
               SDL_Renderer* &Renderer, Texture& gameOver );

#endif // GAMEOVER_H_
