/**
 *	@file ""
 *  	@brief
 **/
#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "../main.h"

class Input {
    public:
        /** Default constructor */
        Input();
        /** Default destructor */
        virtual ~Input();
        void updateEvents();
        const bool finished();
        const bool keyState(const SDL_Scancode);
        const bool mouseKeyState(const Uint8);
        const bool mouseMoved();
        const int getX() ;
        const int getY();
        const int getXRel();
        const int getYRel();
        static void showCursor(bool);
        static void captureCursor(bool);
    protected:
    private:
        SDL_Event event;

        bool keys[SDL_NUM_SCANCODES];
        bool mouseKeys[8];

        int x;
        int y;

        int xRel;
        int yRel;

        bool quit;
};

#endif // INPUT_H_INCLUDED
