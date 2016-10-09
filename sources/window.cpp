//
// Created by chaos on 16-10-9.
//

#include "../headers/window.h"


//初始化 SDL
void InitSDL(){

    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        std::cout<<"Error: "<<SDL_GetError()<<std::endl;
        exit(1);
    }
    IMG_Init(IMG_INIT_PNG);
    printf("Init Successfully.\n");
}


//创建窗口指针
SDL_Window* create_window(int x1=100,int y1=100,int x2=480,int y2=800){

    SDL_Window* win = nullptr;
    win = SDL_CreateWindow("MyWindow",x1,y1,x2,y2,SDL_WINDOW_SHOWN);

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
    ren = SDL_CreateRenderer(win,-1,NULL);
    if(ren == nullptr){
        printf("Create Render Failed![%s]\n" ,SDL_GetError());
        exit(1);
    }
    return ren;
}