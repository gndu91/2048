#include "graphic.h"


namespace cmd {
    int Main(){
        jeu();
        return(0xFFFFFFFF);
    }
    void afficheGrille(Grille g) {

    }
    namespace affichage {
        void resizeScreen(unsigned short int w, unsigned short int h) {
            #ifdef WINDOWS
                string command;
                command = COMMAND_RESIZE;
                command+= " ";
                command+= intToString(w);
                command+= " , ";
                command+= intToString(h);
                system(command.c_str());
                return;
            #else
                #error
            #endif // WINDOWS
        }
        void setTitle(string title) {
            SetConsoleTitle(title.c_str());
        }
        void drawContent(Grille L1, Grille L2) {
            setPos(0,0);
            /** TODO (Ghoul Nadir#1#11/14/15): Verify caches sizes */
            for(int j = 0; j < CACHE_HEIGHT; ++j)
                for(int i = 0; i < CACHE_WIDTH; ++i)
                    if(L1.at(j).at(i) != L2.at(j).at(i)) {
                        cout << L2.at(j).at(i);
                        L1.at(j).at(i) = L2.at(j).at(i);
                    }
        }
    }
}

namespace sdl {

    int Main(){
        return 1;
    }
    void afficheGrille(Grille g) {

    }
    namespace affichage {
        void resizeScreen(unsigned short int w, unsigned short int h) {
        }
        void setTitle(string title) {
            cout << title;
        }
    }
}

namespace opengl {

    int Main(){
        return 1;
    }
    void afficheGrille(Grille g) {

    }
    namespace affichage {
        void resizeScreen(unsigned short int w, unsigned short int h) {

        }
        void setTitle(string title) {
            cout << title;
        }
    }
}
