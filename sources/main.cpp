#include "SDL2/SDL.h"
#include "../headers/window.h"
#include "../headers/image.h"
#include "../headers/lamp.h"
#include <iostream>

int main( int argc, char* args[] ){
    Lamp l("/home/chaos/Temp/white.png");
    l.setComponents(
            "/home/chaos/Temp/lamp1.png",
            "/home/chaos/Temp/lamp2.png",
            "/home/chaos/Temp/slider1.png",
            "/home/chaos/Temp/slider2.png"
    );
    l.run();
}