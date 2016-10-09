//
// Created by chaos on 16-10-9.
//

#ifndef SDLTEST1_WINDOW_H
#define SDLTEST1_WINDOW_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
//初始化函数
void InitSDL();

//用于创建一个窗口
SDL_Window* create_window();

//从一个窗口创建一个渲染器
SDL_Renderer* create_render(SDL_Window* win);

#endif //SDLTEST1_WINDOW_H
