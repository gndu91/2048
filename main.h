#include <vector>
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

/**< To avoid redefinitions, I've replaced const int by define */
    #define GRILL_WIDTH 4
    #define GRILL_HEIGHT 4

    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600

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
