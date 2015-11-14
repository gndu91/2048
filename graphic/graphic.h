#ifndef GRAPHIC_H_INCLUDED
    #define GRAPHIC_H_INCLUDED

    #include "../main.h"

    namespace cmd {
        int Main();
        void afficheGrille ( Grille g);
        namespace affichage {
            void resizeScreen(unsigned short int w,
                              unsigned short int h);
            void setTitle(string title);
            void drawContent(Grille L1cache,
                             Grille L2cache);
        }
    }

    namespace sdl {
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
