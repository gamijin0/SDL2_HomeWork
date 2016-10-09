#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

//图像加载函数
SDL_Surface *load_image( std::string filename )
{
    //加载的图像
    SDL_Surface* loadedImage = NULL;

    //使用SDL_image加载图像
    loadedImage = IMG_Load( filename.c_str() );

    //如果图像为加载成功
    if( loadedImage == NULL )
    {
        printf("Img load Failed! [%s]\n",SDL_GetError());
    }

    //返回图像
    return loadedImage;
}

int main( int argc, char* args[] )
{

    //初始化 SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        std::cout<<"Error: "<<SDL_GetError()<<std::endl;
        exit(1);
    } else{
        printf("Init OK.\n");
    }

    //创建窗口指针
    SDL_Window* win = nullptr;
    win = SDL_CreateWindow("MyWindow",100,100,640,480,SDL_WINDOW_SHOWN
    );

    if(win== nullptr){
        printf("Create Window Failed![%s]\n" ,SDL_GetError());
        exit(1);
    } else{
        printf("Window Creadted.\n");
    }

    //创建渲染器
    SDL_Renderer* ren = nullptr;
    ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(ren == nullptr){
        printf("Create Render Failed![%s]\n" ,SDL_GetError());
        exit(1);
    }

    //读入图片
    SDL_Surface* bmp= nullptr;
    bmp = load_image("/home/chaos/Temp/lamp1.png");
    if(bmp== nullptr){
        printf("Load bmp Failed![%s]\n" ,SDL_GetError());
        exit(1);
    } else{
        printf("One Picture loaded.");
    }

    //加载图片
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren,bmp);//把SDL_Surface转化为SDL_Texture方便renderer绘制
    SDL_FreeSurface(bmp);

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren,tex,NULL,NULL);
    SDL_RenderPresent(ren);



    SDL_Delay(2000);


//    销毁资源,关闭 SDL
//    SDL_DestroyTexture(tex);
//    SDL_DestroyRenderer(ren);
//    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}