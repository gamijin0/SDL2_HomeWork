#include "SDL2/SDL.h"
#include "../headers/window.h"
#include "../headers/image.h"


int main( int argc, char* args[] )
{

    InitSDL();

    SDL_Window* win =create_window(100,100,980,800);

    SDL_Renderer* ren = create_render(win);

    //读入图片
    SDL_Texture* bmp = loadTexture("/home/chaos/Temp/white.png",ren);
    BiltTexture(0,0,bmp,ren);

    SDL_Surface* lamp = load_image("/home/chaos/Temp/lamp1.png");
    remove_background(lamp,0,0,0);
    BiltTexture(100,200,SDL_CreateTextureFromSurface(ren,lamp),ren);


    SDL_RenderPresent(ren);


    SDL_Delay(4000);


    SDL_Quit();

    return 0;
}