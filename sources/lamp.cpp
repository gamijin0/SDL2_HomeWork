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


Lamp::Lamp(const std::string& filepath)  {
        //初始化SDL
        InitSDL();
        //创建窗口
        win =create_window(100,100,980,800);
        //创建渲染器
        ren = create_render(win);
        //设置帧率上限
        Frame = 100;
        //设置背景图片路径
        this->s_background=filepath;
        //读取背景图片
        this->background = load_image(this->s_background);
        //渲染背景
        BiltTexture(
                0,
                0,
                SDL_CreateTextureFromSurface(this->ren,this->background),
                this->ren,
                1
        );

}

void Lamp::run() {
    float TimeStart = 0;
    float TimeEnd = 0;
    while (true){

        //获得开始时间
        TimeStart = SDL_GetTicks();
        this->draw();
        //获得结束时间
        TimeEnd = SDL_GetTicks();

        // 如果绘制过快,则控制帧率
        if ((TimeEnd - TimeStart) < (1000 / Frame))
        {
            SDL_Delay((1000 / Frame) - (TimeEnd - TimeStart));
        }

        //将内存中的画面渲染到屏幕上
        this->update();
    }
}

void Lamp::update() {
    SDL_RenderPresent(this->ren);
}

void Lamp::draw() {

}

void Lamp::setComponents(
        const std::string &lamp,
        const std::string &slider_background,
        const std::string &slider) {



}