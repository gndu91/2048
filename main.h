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
    #define CHAR_VOID ' '
    #define  DOUBLE_LINES
    #ifdef STARS
        #define DOUBLE_LINES
        #define SIMPLE_LINES
    #endif // STARS

    #ifndef DOUBLE_LINES
        #define CHAR_LINE_H              196
        #define CHAR_LINE_V              179

        #define CHAR_CORNER_TOP_RIGHT    191
        #define CHAR_CORNER_TOP_LEFT     218
        #define CHAR_CORNER_BOTTOM_RIGHT 217
        #define CHAR_CORNER_BOTTOM_LEFT  192

        #define CHAR_T_BOTTOM            193
        #define CHAR_T_TOP               194
        #define CHAR_T_LEFT              195
        #define CHAR_T_RIGHT             180

        #define CHAR_CROSS               197
    #endif // DOUBLE_LINES

    #ifndef SIMPLE_LINES
        #define CHAR_LINE_H              205
        #define CHAR_LINE_V              186

        #define CHAR_CORNER_TOP_RIGHT    187
        #define CHAR_CORNER_TOP_LEFT     201
        #define CHAR_CORNER_BOTTOM_RIGHT 188
        #define CHAR_CORNER_BOTTOM_LEFT  200

        #define CHAR_T_TOP               203
        #define CHAR_T_BOTTOM            202
        #define CHAR_T_LEFT              204
        #define CHAR_T_RIGHT             185

        #define CHAR_CROSS               206
    #endif // SIMPLE_LINES

    #ifdef STARS
        #define CHAR_LINE_H              42///'*'
        #define CHAR_LINE_V              42///'*'

        #define CHAR_CORNER_TOP_RIGHT    42///'*'
        #define CHAR_CORNER_TOP_LEFT     42///'*'
        #define CHAR_CORNER_BOTTOM_RIGHT 42///'*'
        #define CHAR_CORNER_BOTTOM_LEFT  42///'*'

        #define CHAR_T_TOP               42///'*'
        #define CHAR_T_BOTTOM            42///'*'
        #define CHAR_T_LEFT              42///'*'
        #define CHAR_T_RIGHT             42///'*'

        #define CHAR_CROSS               42///'*'
    #endif

    #define CHAR_BLOCK 219

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

#define CHAR_VOID ' '
