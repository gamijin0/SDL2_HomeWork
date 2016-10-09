//
// Created by chaos on 16-10-9.
//

#ifndef SDLTEST1_IMAGE_H
#define SDLTEST1_IMAGE_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

//图像加载函数
SDL_Surface *load_image( std::string filename );

//图像加载函数
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);

//表面复制
void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* destination);

//将指定颜色设置为透明
void remove_background(SDL_Surface* su,Uint8 r,Uint8 g,Uint8 b);

//绘图函数,最后一个参数为放大倍数
void BiltTexture(int x, int y, SDL_Texture * Draw_Texture,SDL_Renderer *Draw_Render, float size);


#endif //SDLTEST1_IMAGE_H
