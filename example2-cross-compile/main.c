#include <stdio.h>
#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
# include <emscripten.h>
#endif

void run();
SDL_Texture* createTexture(SDL_Renderer*);

typedef struct {
    SDL_Texture* texture;
    SDL_Renderer* renderer;
} World;

int main(int argc, char* argv[])
{
	printf("hello, world!\n");
	run();
 	return 0;
}

void frame(void* ctx)
{
    World* world = (World*)ctx;
	SDL_RenderClear(world->renderer);
	SDL_RenderCopy(world->renderer, world->texture, NULL, NULL);
	SDL_RenderPresent(world->renderer);
}

void run()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* const win =
		SDL_CreateWindow("Hello World!", 100, 100, 256, 256, SDL_WINDOW_SHOWN);

    World world;
    world.renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    world.texture = createTexture(world.renderer);

#ifdef TEST_SDL_LOCK_OPTS
	EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
#endif

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(frame, &world, -1, 1);
#else
    int running = 1;
    while (running)
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev) != 0)
        {
            if (ev.type == SDL_QUIT)
                running = 0;
        }
        frame(&world);
    }
#endif

	SDL_DestroyTexture(world.texture);
	SDL_DestroyRenderer(world.renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

SDL_Texture* createTexture(SDL_Renderer* const ren)
{
    SDL_Surface* const surface = SDL_LoadBMP("image.bmp");
    SDL_Texture* const texture = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    return texture;
}
