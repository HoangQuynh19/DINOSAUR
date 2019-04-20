#ifndef LOADTEXTURE_H_
#define LOADTEXTURE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;

class LTexture
{
	public:
		LTexture();
		~LTexture();

		bool loadTexture( std::string path,SDL_Renderer* gRenderer );

		void free();

		void render( int x, int y, SDL_Renderer* gRenderer,SDL_Rect* clip );

		int getWidth();
		int getHeight();

	private:

		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};


#endif // LOADTEXTURE_H_
