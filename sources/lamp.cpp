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
        this->width=900;
        this->height=600;
        win =create_window(100,100,100+this->width,100+this->height);
        //创建渲染器
        ren = create_render(win);
        //设置帧率上限
        Frame = 300;
        //设置背景图片路径
        this->s_background=filepath;
        //读取背景图片
        this->background = SDL_GetWindowSurface(this->win);

        //渲染背景
        this->back = load_image(this->s_background);
        apply_surface(0,0,back,this->background);

        //默认关灯状态
        this->On= false;
}

void Lamp::run() {
    if(     this->s_lamp_on.length()==0||
            this->s_lamp_off.length()==0||
            this->s_slider_background.length()==0||
            this->s_slider.length()==0)
    {
        std::cout<<"Please init the components first!"<<std::endl;
        exit(1);
    }
    float TimeStart = 0;
    float TimeEnd = 0;
    while (1){

        this->listen();

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

    }
}

void Lamp::draw() {
    SDL_UpdateWindowSurface(win);
    //开始渲染下一次的背景
    apply_surface(0,0,this->back,this->background);
    if(this->On){
        apply_surface(400,200,this->lamp_on,this->background);
    } else{
        apply_surface(400,200,this->lamp_off,this->background);
    }
    apply_surface(this->width/2-80,this->height/2+100,this->slider_background,this->background);
    apply_surface(this->slider_x,this->height/2+105,this->slider,this->background);
}

void Lamp::setComponents(
        const std::string &lamp_on,
        const std::string &lamp_off,
        const std::string &slider_background,
        const std::string &slider)
{

    this->s_lamp_on = lamp_on;
    this->s_lamp_off = lamp_off;
    this->s_slider_background = slider_background;
    this->s_slider = slider;

    this->lamp_on = load_image(lamp_on);
    remove_background(this->lamp_on,0,0,0);
    this->lamp_off =load_image(lamp_off);
    remove_background(this->lamp_off,0,0,0);
    this->slider_background = load_image(slider_background);
    remove_background(this->slider_background,0,0,0);
    this->slider = load_image(slider);
    this->slider_x=380;

//    apply_surface(380,410,this->slider,this->background);

}

Lamp::~Lamp() {
    SDL_Quit();
}

void Lamp::listen() {
    int x,y;
    int state = SDL_GetMouseState(&x,&y);
    while (SDL_PollEvent(&this->event)){

        if(event.type==SDL_MOUSEMOTION && InArea() && event.button.button == SDL_BUTTON_LEFT) {
                if (x >= 430 && x <= 530) {
                slider_x = x - 50;
                    if(x>500){
                        this->On=true;
                    } else{
                        this->On= false;
                    }
            }
        }
        if(event.type==SDLK_ESCAPE||event.type==SDL_QUIT){
            SDL_Quit();
        }
    }
}


bool Lamp::InArea() {
    int x,y;
    SDL_GetMouseState(&x,&y);
    if(x>=this->slider_x-10&&x<this->slider_x+120){
        if(y>=410&&y<=500)
        {
            return true;
        }

    }
    return false;
}