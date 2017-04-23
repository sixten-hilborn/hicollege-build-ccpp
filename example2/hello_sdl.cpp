#include <string>
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
//#include <boost/noncopyable.hpp>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

void run();
SDL_Texture* createTexture(SDL_Renderer*);

extern "C" int main(int argc, char** argv)
{
	printf("hello, world!\n");
	{
		std::ifstream fin("foo.txt");
		std::cout << "foo.txt:" << std::endl;
		while (fin)
		{
			std::string s;
			getline(fin, s);
			std::cout << s << std::endl;
		}
	}
	run();
 	return 0;
}

void run()
{
	SDL_Init(SDL_INIT_VIDEO);
	//SDL_Surface* screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);
	SDL_Window* const win =
		SDL_CreateWindow("Hello World!", 100, 100, 256, 256, SDL_WINDOW_SHOWN);
	SDL_Renderer* const ren = 
		SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

#ifdef TEST_SDL_LOCK_OPTS
	EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif

	SDL_Texture* const tex = createTexture(ren);

	//SDL_Flip(screen);
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, nullptr, nullptr);
	SDL_RenderPresent(ren);

	std::cout << "do you see anything??\n";

	SDL_Delay(2000);
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

SDL_Texture* createTexture(SDL_Renderer* const ren)
{
	{
		SDL_Surface* const surface = SDL_LoadBMP("image.bmp");
		std::cout << "surface: " << surface << std::endl;
		SDL_Texture* const texture = SDL_CreateTextureFromSurface(ren, surface);
		SDL_FreeSurface(surface);
		return texture;
	}

	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	Uint32 rmask = 0xff000000;
	Uint32 gmask = 0x00ff0000;
	Uint32 bmask = 0x0000ff00;
	Uint32 amask = 0x000000ff;
	#else
	Uint32 rmask = 0x000000ff;
	Uint32 gmask = 0x0000ff00;
	Uint32 bmask = 0x00ff0000;
	Uint32 amask = 0xff000000;
	#endif

	SDL_Surface* const screen =
		SDL_CreateRGBSurface(0, 256, 256, 32, rmask, gmask, bmask, amask);

	if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			int alpha = 255;
			*((Uint32*)screen->pixels + i * 256 + j) = SDL_MapRGBA(screen->format, i, j, 255-i, alpha);
		}
	}
	if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
	SDL_Texture* const tex = SDL_CreateTextureFromSurface(ren, screen);
	SDL_FreeSurface(screen);
	return tex;
}
