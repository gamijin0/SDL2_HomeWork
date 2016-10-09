#include "SDL2/SDL.h"
#include "../headers/window.h"
#include "../headers/image.h"


int main( int argc, char* args[] )
{

    InitSDL();

    SDL_Window* win =create_window();

    SDL_Renderer* ren = create_render(win);

    //读入图片
    SDL_Surface* bmp= nullptr;
    bmp = load_image("/home/chaos/Temp/white.png");

    //加载图片
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren,bmp);//把SDL_Surface转化为SDL_Texture方便renderer绘制
    SDL_FreeSurface(bmp);

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,tex,NULL,NULL);

    SDL_RenderPresent(ren);


    SDL_Delay(2000);


    SDL_Quit();

    return 0;
}