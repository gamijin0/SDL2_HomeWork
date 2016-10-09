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
    std::string s_lamp_on;
    std::string s_lamp_off;
    std::string s_background;
    std::string s_slider_background;
    std::string s_slider;

    //软件资源
    SDL_Window* win;
    SDL_Renderer* ren;
    SDL_Surface* background;
    SDL_Surface* back;
    SDL_Surface* lamp_on;
    SDL_Surface* lamp_off;
    SDL_Surface* slider_background;
    SDL_Surface* slider;
    SDL_Event event;

    //变量定义
    int Frame;
    int width;
    int height;
    int slider_x;


    //初始化函数
    Lamp(const std::string&);

    //析构函数
    ~Lamp();

    //运行函数
    void run();

    //更新画面
    void update();

    //内存中绘制画面
    void draw();

    //初始化组件
    void setComponents(
            const std::string& lamp_on,
            const std::string& lamp_off,
            const std::string& slider_background,
            const std::string& slider);

    //监听
    void listen();

    bool InArea();
};


#endif //SDLTEST1_LAMP_H
