//
// Created by chaos on 16-10-9.
//

#include "../headers/window.h"


//初始化 SDL
void InitSDL(){

    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        std::cout<<"Error: "<<SDL_GetError()<<std::endl;
        exit(1);
    } else{
        printf("Init Successfully.\n");
    }
}


//创建窗口指针
SDL_Window* create_window(){

    SDL_Window* win = nullptr;
    win = SDL_CreateWindow("MyWindow",100,100,640,480,SDL_WINDOW_SHOWN
    );

    if(win== nullptr){
        printf("Create Window Failed![%s]\n" ,SDL_GetError());
        exit(1);
    } else{
        printf("Window Creadted Successfully.\n");
        return win;
    }
}

//从窗口创建渲染器
SDL_Renderer* create_render(SDL_Window* win){
    SDL_Renderer* ren = nullptr;
    ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    if(ren == nullptr){
        printf("Create Render Failed![%s]\n" ,SDL_GetError());
        exit(1);
    }
    return ren;
}