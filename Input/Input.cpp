/**
 *	@file " Name)"
 *  	@brief
 **/
#include "Input.h"

Input::Input() : x(0), y(0), xRel(0), yRel(0), quit(false) {
    for(int i(0); i < SDL_NUM_SCANCODES; i++)
        this->keys[i] = false;
    for(int i(0); i < 8; i++)
        this->mouseKeys[i] = false;
}

Input::~Input() {
    //dtor
}

const bool Input::keyState(const SDL_Scancode code) {
    this->updateEvents();
    if(code < 0)
        return false;
    if(code >= SDL_NUM_SCANCODES)
        return false;
    return keys[code];
}

const bool Input::mouseKeyState(const Uint8 code) {
    this->updateEvents();
    if(code < 0)
        return false;
    if(code >= 8)
        return false;
    return mouseKeys[code];
}

const bool Input::mouseMoved() {
    this->updateEvents();
    return this->xRel&&this->yRel;
}

const int Input::getX() {
    this->updateEvents();
    return this->x;
}

const int Input::getY() {
    this->updateEvents();
    return this->y;
}

const int Input::getXRel() {
    this->updateEvents();
    return this->xRel;
}

const int Input::getYRel() {
    this->updateEvents();
    return this->yRel;
}

const bool Input::finished() {
    this->updateEvents();
    return this->quit;
}

void Input::updateEvents() {

    this->yRel = 0;
    this->xRel = 0;

    while(SDL_PollEvent(&this->event)) {
        switch(this->event.type) {
            case SDL_KEYDOWN:
                this->keys[this->event.key.keysym.scancode] = true;
                break;
            case SDL_KEYUP:
                this->keys[this->event.key.keysym.scancode] = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                this->mouseKeys[this->event.button.button] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                this->mouseKeys[this->event.button.button] = false;
                break;
            case SDL_MOUSEMOTION:
                this->x = this->event.motion.x;
                this->y = this->event.motion.y;

                this->xRel = this->event.motion.xrel;
                this->yRel = this->event.motion.yrel;
                break;
            case SDL_WINDOWEVENT:
                    switch(this->event.window.event) {
                        case SDL_WINDOWEVENT_CLOSE:
                            this->quit = true;
                            break;
                        default:
                            break;
                    }
                    break;
            default:
                break;
        }
    }
}

void Input::showCursor(bool show) {
    SDL_ShowCursor(show);
}

void Input::captureCursor(bool capture) {
    SDL_SetRelativeMouseMode(  (SDL_bool)( (int)capture )  );///Conversios forcées (la flemme de faire 3l de +
}
