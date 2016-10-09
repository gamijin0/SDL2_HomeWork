//
// Created by chaos on 16-10-9.
//
#include <iostream>
#include "../headers/image.h"

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
    } else{
        printf("Pic[\"%s\"] loaded sucessfully.\n",filename.c_str());
    }

    //返回图像
    return loadedImage;
}


//表面复制
void apply_surface(int x,int y,SDL_Surface* source,SDL_Surface* destination){
    //偏移矩形
    SDL_Rect offset;
    offset.x=x;
    offset.y=y;
    SDL_BlitSurface(source,NULL,destination,&offset);
}


//将指定颜色设置为透明
void remove_background(SDL_Surface* su,Uint8 r,Uint8 g,Uint8 b){
    SDL_SetColorKey(su,SDL_TRUE,SDL_MapRGB(su->format,r,g,b));
}

//图像加载函数
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
    SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
    if (texture == nullptr){
        std::cout<<"Pic[%s] load Failed! :"<<SDL_GetError()<<std::endl;
    } else{
        printf("Pic[\"%s\"] loaded sucessfully.\n",file.c_str());
    }
    return texture;
}


void BiltTexture(int x, int y, SDL_Texture * Draw_Texture,
                SDL_Renderer * Draw_Render)
{
    SDL_Rect Draw_Render_Rect;
    Draw_Render_Rect.x = x;
    Draw_Render_Rect.y = y;
    int w = 0, h = 0;
    SDL_QueryTexture(Draw_Texture, NULL, NULL, &w, &h);
    Draw_Render_Rect.w = w;
    Draw_Render_Rect.h = h;

    SDL_RenderCopy(Draw_Render, Draw_Texture, NULL, &Draw_Render_Rect);
}