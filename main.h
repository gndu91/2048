/** Define constants    */
    /**< About system   */
        #define WINDOWS

/** Include libraries */

    /** Defaults */
        #include <vector>
        #include <cmath>
        #include <cstdlib>
        #include <windows.h>
        #include <conio.h>
        #include <ctime>

    /**< Of the project */
        #ifndef JINC
            #define JINC
            #include "jeu/jeu.h"
        #endif // JINC

        #ifndef GINC
            #define GINC
            #include "grille/grille.h"
        #endif // GINC

        #ifndef IINC
            #define IINC
            #include "input/Input.h"
        #endif // IINC

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

    #define SDL

using namespace std;
    #ifdef SDL
        namespace sdl {
            int main(int,char**);
        }
        using namespace sdl;
        #include <iostream>
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
    #endif // OPENGL
    #endif // SDL
    #ifdef WINDOWS
        #define COMMAND_CLEAR "cls"
        #define COMMAND_RESIZE "mode"
        #include <windows.h>
    #else
        #ifdef LINUX
            #define COMMAND_CLEAR "clear"
        #else
            #error no OS specified
        #endif // LINUX
    #endif // WINDOWS

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

    #define TITLE_STYLE_2

    #define CASE_SPACE 5
    #warning TODO (Ghoul Nadir#1#11/21/15): Auto resize it
    #define charSize   CASE_SPACE

    #define CHAR_LINE_HORIZONTAL    CHAR_LINE_H
    #define CHAR_LINE_VERTICAL      CHAR_LINE_V

    #define GAME_SIZE_W 4
    #define GAME_SIZE_H 4

    #define UP      00
    #define CENTER  50
    #define DOWN    100

    #define LEFT    0
    #define MIDDLE  5
    #define RIGHT   10

