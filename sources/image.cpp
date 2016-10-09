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
        printf("Pic[\"%s\"] loaded sucessfully.",filename.c_str());
    }

    //返回图像
    return loadedImage;
}