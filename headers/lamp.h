//
// Created by chaos on 16-10-9.
//

#ifndef SDLTEST1_LAMP_H
#define SDLTEST1_LAMP_H

//
// Created by chaos on 16-10-9.
//
#include <iostream>
#include <string>
#include "../headers/lamp.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../headers/window.h"
#include "../headers/image.h"


class Lamp{

public:
    //物理资源
    std::string s_lamp;
    std::string s_background;
    std::string s_slider_background;
    std::string s_slider;

    //软件资源
    SDL_Window* win;
    SDL_Renderer* ren;
    SDL_Surface* lamp;
    SDL_Surface* background;
    SDL_Surface* slider_background;
    SDL_Surface* slider;

    //变量定义
    int Frame;

    //初始化函数
    Lamp(const std::string&);

    //运行函数
    void run();

    //更新画面
    void update();

    //内存中绘制画面
    void draw();

    void setComponents(
            const std::string& lamp,
            const std::string& slider_background,
            const std::string& slider);
};

#endif //SDLTEST1_LAMP_H
