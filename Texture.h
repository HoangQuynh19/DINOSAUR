#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 550;

class Texture
{
	public:
		Texture();
		~Texture();

		bool loadTexture( std::string path,SDL_Renderer* Renderer );

		void free();

		void render( int x, int y, SDL_Renderer* Renderer,SDL_Rect* clip );

		int getWidth();
		int getHeight();

	private:

		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};

#endif // TEXTURE_H_
