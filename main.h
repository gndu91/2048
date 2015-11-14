#include <vector>
#include <cmath>
#include <cstdlib>

#define WINDOWS

#ifndef JINC
    #define JINC
    #include "jeu/jeu.h"
#endif // JINC

#ifndef GINC
    #define GINC
    #include "grille/grille.h"
#endif // GINC

#ifndef G2INC
    #define G2INC
    #include "graphic/graphic.h"
#endif // G2INC

#ifndef F2INC
    #define F2INC
    #include "functions/functions.h"
#endif // F2INC

/**< To avoid redefinitions, I've replaced const int by define */
    #define GRILL_WIDTH     4
    #define GRILL_HEIGHT    4

    #define WINDOW_WIDTH    800
    #define WINDOW_HEIGHT   600


    #define SCREEN_WIDTH    95
    #define SCREEN_HEIGHT   35

    #define GAUCHE  7
    #define DROITE  4
    #define HAUT    8
    #define BAS     2

using namespace std;
#ifdef SDL
    namespace sdl {
        int main(int,char**);
    }
    using namespace sdl;
    #include <string>
    #include <SDL2/SDL.h>

#else
    #ifdef OPENGL
        namespace opengl {
            int main(int,char**);
        }
        using namespace opengl;
        #include <string>
        #include <SDL2/SDL.h>
    #else
        namespace cmd {
            int main(int,char**);
        }
        using namespace cmd;
        #include <iostream>
        #ifdef WINDOWS
            #define COMMAND_CLEAR "cls"
            #define COMMAND_RESIZE "mode"
            #include <windows.h>
        #else
            #ifdef LINUX
                 #define COMMAND_CLEAR "clean"
            #else
                #error no OS specified
            #endif // LINUX
        #endif // WINDOWS

    #endif // OPENGL
#endif // SDL

typedef vector<vector<int>> Grille  ;
typedef vector<int>         Ligne   ;

#define FOOTER_HEIGHT 1

#define HEADER_HEIGHT 3

#define CACHE_MARGIN_UP     HEADER_HEIGHT
#define CACHE_MARGIN_LEFT   1
#define CACHE_MARGIN_RIGHT  1
#define CACHE_MARGIN_DOWN   FOOTER_HEIGHT

#define CACHE_HEIGHT        SCREEN_HEIGHT   -   CACHE_MARGIN_UP     - CACHE_MARGIN_DOWN
#define CACHE_WIDTH         SCREEN_WIDTH    -   CACHE_MARGIN_LEFT   - CACHE_MARGIN_RIGHT
