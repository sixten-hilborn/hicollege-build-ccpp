CFLAGS = -O2 #-lSDL2 -O0
	#-I/home/sixten/Downloads/SDL2-2.0.4/build \
	#-L/home/sixten/Downloads/SDL2-2.0.4/build \

all:
	g++ hello_sdl.cpp -o hello_sdl -lSDL2 -std=c++14

em:
	em++ hello_sdl.cpp -std=c++14 $(CFLAGS) -o hello_sdl.html --preload-file image.bmp --preload-file foo.txt -s USE_SDL=2

