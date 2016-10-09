#include "SDL2/SDL.h"
#include "../headers/window.h"
#include "../headers/image.h"
#include "../headers/lamp.h"
#include <iostream>
//
//int main( int argc, char* args[] )
//{
//
//    InitSDL();
//
//    SDL_Window* win =create_window(100,100,980,800);
//
//    SDL_Renderer* ren = create_render(win);
//    int x=100,y=200,r=64;
//    float TimeStart = 0;
//    float TimeEnd = 0;
//    int Frame=300;
//    //读入图片
//    SDL_Texture* bmp = loadTexture("/home/chaos/Temp/white.png",ren);
//    BiltTexture(0,0,bmp,ren,1);
//
//    SDL_Surface* lamp = load_image("/home/chaos/Temp/lamp1.png");
//    remove_background(lamp,0,0,0);
//    BiltTexture(x,y,SDL_CreateTextureFromSurface(ren,lamp),ren,1);
//
//    SDL_Surface* lamp2 = load_image("/home/chaos/Temp/slider1.png");
//    remove_background(lamp2,0,0,0);
//    BiltTexture(300,200,SDL_CreateTextureFromSurface(ren,lamp2),ren,0.35);
//
//    SDL_RenderPresent(ren);
//
//
//    SDL_Event event;
//    SDL_Event movEvent;
//    while (true)
//    {
//        while (SDL_PollEvent(&event))
//        {
//            if (event.type == SDL_MOUSEMOTION)
//            {
////                std::cout<<"Click on ["<<event.button.x<<","<<event.button.y<<"]."<<std::endl;
//
//                    // 获得当前时间
//                    TimeStart = SDL_GetTicks();
//
//                    BiltTexture(0,0,bmp,ren,1);
//                if(event.button.x>200&&event.button.x<500) {
//                    BiltTexture(event.button.x - 64, event.button.y - 64, SDL_CreateTextureFromSurface(ren, lamp), ren,
//                                1);
//                    SDL_RenderPresent(ren);
//                }
//
//
//                    // 获得结束时间
//                    TimeEnd = SDL_GetTicks();
//                    // 如果绘制过快
//                    if ((TimeEnd - TimeStart) < (1000 / Frame))
//                    {
//                        SDL_Delay((1000 / Frame) - (TimeEnd - TimeStart));
//                    }
//
//            }
//        }
//    }
//
//    SDL_Quit();
//
//    return 0;
//}

int main( int argc, char* args[] ){
    Lamp l("/home/chaos/Temp/white.png");
    l.run();
}