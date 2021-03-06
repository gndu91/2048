#ifndef GRAPHIC_H_INCLUDED
    #define GRAPHIC_H_INCLUDED

    #include "../main.h"

    namespace cmd {
        int Main();
        void afficheGrille ( Grille g);
        namespace affichage {
            void cursor(bool hide);
            void resizeScreen(unsigned short int w,
                              unsigned short int h);
            void setTitle(string Title);
            void drawContent(Grille L1cache,
                             Grille L2cache);
        }
        short getMove(bool block = false);
    }

    namespace sdl {
        void init(string title = "2048");
        void destroy();
        void hide();
        void show();
        void update();
        int Main();
        void afficheGrille ( Grille g);
        namespace affichage {
            void resizeScreen(unsigned short int w,
                              unsigned short int h);
            void setTitle(string title);
        }
    }

    namespace opengl {
        int Main();
        void afficheGrille ( Grille g);
        namespace affichage {
            void resizeScreen(unsigned short int w,
                              unsigned short int h);
            void setTitle(string title);
        }
    }

#endif // GRAPHIC_H_INCLUDED
