#include "graphic.h"


namespace cmd {
    int Main(){
        jeu();
        return(0xFFFFFFF);
    }
    void afficheGrille(Grille g){
        int w((GAME_SIZE_W*(charSize+1))+1),h(GAME_SIZE_H*2+1);
        /**< define the size, and add lines in columns */
        vector<vector<char> > cache = vector<vector<char> >(h,vector<char>(w)) ;
        for(unsigned int j = 0; j < cache.size();++j) {
            for(unsigned int i = 0; i < cache[j].size();++i) {
                if(j == 0) {
                    if(j%2 == 0)
                        cache[j][i] = CHAR_LINE_HORIZONTAL;
                    if(i == 0)
                        cache[j][i] = CHAR_CORNER_TOP_LEFT;
                    else if(i%(charSize+1) == 0)
                        cache[j][i] = CHAR_T_TOP;
                    if(i == w-1)
                        cache[j][i] = CHAR_CORNER_TOP_RIGHT;
                }
                else if(j == h-1) {
                    if(j%2 == 0)
                        cache[j][i] = CHAR_LINE_HORIZONTAL;
                    if(i == 0)
                        cache[j][i] = CHAR_CORNER_BOTTOM_LEFT;
                    else if(i%(charSize+1) == 0)
                        cache[j][i] = CHAR_T_BOTTOM;
                    if(i == w-1)
                        cache[j][i] = CHAR_CORNER_BOTTOM_RIGHT;
                }
                else {
                    if(i == 0) {
                        cache[j][i] = CHAR_LINE_VERTICAL;
                        if(j%2 == 0)
                            cache[j][i] = CHAR_T_LEFT;
                    }
                    else if(i == w-1) {
                        cache[j][i] = CHAR_LINE_VERTICAL;
                        if(j%2 == 0)
                            cache[j][i] = CHAR_T_RIGHT;
                    }
                    else {
                        if(i%(charSize+1) == 0 and j%2 == 0)
                            cache[j][i] = CHAR_CROSS;
                        else if(j%2 == 0)
                            cache[j][i] = CHAR_LINE_HORIZONTAL;
                        else if(i%(charSize+1) == 0)
                            cache[j][i] = CHAR_LINE_VERTICAL;
                    }
                }
            }
        }
        for(unsigned int j = 0; j < g.size();++j)
            for(unsigned int i = 0; i < g[j].size();++i) {
                for(unsigned int k = 0; k < charSize;++k)
                    cache.at(j*2+1).at((charSize+1)*i+1+k) = CHAR_VOID;
                string  number = intToString(g[j][i]);
                int     beginX = (charSize+1)*i+1+((charSize/2)-(number.size()/2));
                int     beginY = j*2+1;
                for(unsigned int k = 0; k < number.size();++k)
                    cache.at(beginY).at(beginX+k) = number.at(k);
            }
        for( auto lines : cache) {
            for( auto cases : lines)
                cout << cases;
            cout << endl;
        }
    }
    namespace affichage {
        string title = "2048";
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
            setTitle(title);
        }
        void setTitle(string Title) {
            title = Title;
            #ifdef WINDOWS
                SetConsoleTitle(Title.c_str());
            #else
                #error
            #endif // WINDOWS
            #ifdef TITLE_STYLE_0
                for(auto i = 0;i < SCREEN_WIDTH;++i)
                    putch(char(CHAR_BLOCK));
                for(auto i = 0;i < SCREEN_WIDTH;++i)
                    putch(char(CHAR_BLOCK));
                for(auto i = 0;i < SCREEN_WIDTH;++i)
                    putch(char(CHAR_BLOCK));
                setPos((SCREEN_WIDTH/2) - (Title.size()/2) -1 ,1);
                putch(char(CHAR_VOID));
                cout << Title;
                putch(char(CHAR_VOID));
            #endif // TITLE_STYLE_0
            #ifdef TITLE_STYLE_1
                for(auto i = 0;i < SCREEN_WIDTH;++i)
                    cout << char(CHAR_LINE_HORIZONTAL);
                for(auto i = 0;i < SCREEN_WIDTH;++i)
                    cout << char(CHAR_LINE_HORIZONTAL);
                for(auto i = 0;i < SCREEN_WIDTH;++i)
                    cout << char(CHAR_LINE_HORIZONTAL);
                setPos((SCREEN_WIDTH/2) - (Title.size()/2) -2 ,0);
                cout << char(CHAR_T_TOP);
                setPos((SCREEN_WIDTH/2) + (Title.size()/2) + 1, 0);
                cout << char(CHAR_T_TOP);
                setPos((SCREEN_WIDTH/2) - (Title.size()/2) -2 ,2);
                cout << char(CHAR_T_BOTTOM);
                setPos((SCREEN_WIDTH/2) + (Title.size()/2) + 1, 2);
                cout << char(CHAR_T_BOTTOM);
                setPos((SCREEN_WIDTH/2) - (Title.size()/2) -2 ,1);
                cout << char(CHAR_T_RIGHT) << char(CHAR_VOID) << Title << char(CHAR_VOID) << char(CHAR_T_LEFT);
            #endif // TITLE_STYLE_BLOCK
            #ifdef TITLE_STYLE_2
                setPos((SCREEN_WIDTH/2) - (Title.size()/2) -2 ,0);
                putch(char(CHAR_CORNER_TOP_LEFT));
                for(int i = 0; i < Title.size() + 2;++i)
                    cout << char(CHAR_LINE_HORIZONTAL);
                setPos((SCREEN_WIDTH/2) + (Title.size()/2) + 1, 0);
                cout << char(CHAR_CORNER_TOP_RIGHT);
                setPos((SCREEN_WIDTH/2) - (Title.size()/2) -2 ,2);
                cout << char(CHAR_CORNER_BOTTOM_LEFT);
                for(int i = 0; i < Title.size() + 2;++i)
                    cout << char(CHAR_LINE_HORIZONTAL);
                setPos((SCREEN_WIDTH/2) + (Title.size()/2) + 1, 2);
                cout << char(CHAR_CORNER_BOTTOM_RIGHT);
                setPos((SCREEN_WIDTH/2) - (Title.size()/2) -2 ,1);
                cout << char(CHAR_LINE_VERTICAL) << char(CHAR_VOID) << Title << char(CHAR_VOID) << char(CHAR_LINE_VERTICAL);
            #endif // TITLE_STYLE_BLOCK
            setPos(0,3);
        }
        void drawContent(Grille L1, Grille L2) {
            /** TODO (Ghoul Nadir#1#11/14/15): Verify caches sizes */
            for(int j = 0; j < CACHE_HEIGHT; ++j)
                for(int i = 0; i < CACHE_WIDTH; ++i)
                    if(L1.at(j).at(i) != L2.at(j).at(i)) {
                        setPos(i,j);
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
            ///throw runtime_error("Missing function");
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
