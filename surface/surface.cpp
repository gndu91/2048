/**
 *	@file " Name)"
 *  	@brief
 **/
#include "surface.h"

surface::surface() {
    location = {0,0,0,0};
}

surface::~surface() {
    //dtor
}

void surface::draw(SDL_Renderer&) {
    for(int i = 0; i < pixels.size(); ++i) {

    }
}
