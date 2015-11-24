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
        void cursor(bool hide) {
            CONSOLE_CURSOR_INFO cci;

            GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

            cci.bVisible = not hide;
            SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
        }
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
    short getMove(bool block) {
        ///exit(putenv('a'));
        ///if(getch() == 27) Escape    exit(12);
        /**< TODO:Use curse pour linux */
        /**< TODO:Use toupper */
        ///cout << char(toupper('a')) << char(tolower(toupper('a')));
        ///_cputs("");
        ///_getch();
        /// std::cin.putback('T');
        char c;
        if(kbhit()) {
            c = toupper(_getch());
            switch(c) {
                case 'Z':
                    return HAUT;
                case 'S':
                    return BAS;
                case 'D':
                    return DROITE;
                case 'Q':
                    return GAUCHE;
                default:
                    return 0;
            }
        } else return 0;
    }
}

namespace sdl {
    int j(0);
    SDL_Window* window(0);
    SDL_Renderer* renderer = 0;
    vector<SDL_Rect> content;
    Input input;
    void init(string title) {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {            cerr << "Error with SDL : " << SDL_GetError() << endl;            SDL_Quit();            exit(-1);        }        atexit(SDL_Quit);
        SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer); // SDL_WINDOW_SHOWN|SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC,&win,&ren);
        SDL_SetWindowTitle(window,title.c_str());
    }
    void hide() {
        SDL_HideWindow(window);
    }
    void show() {
        SDL_ShowWindow(window);
    }
    void destroy() {/*
        for(auto s : content)
            SDL_free(s);*/
        #warning
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
    void update() {

        ///Set color
        /*
        for(auto s : content) {
            SDL_RenderFillRect(renderer, &s);
        }*/
        ////SDL_UpdateWindowSurface(window);

        for(int i = 0; i < 640; ++i) {
            if((i+j)%3==1)
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            else if((i+j)%3==0)
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            SDL_RenderDrawPoint(renderer, i, j);
        }
        SDL_RenderPresent(renderer);
        ///Reset background
        SDL_SetRenderDrawColor(renderer, 127, 127, 128, 127);
        ///SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    int Main(){
        init();
        /**
        ///Input::showCursor(false);
        ///SDL_GetTicks();
        for(auto s : content)
            SDL_BlitSurface(s.content, NULL, SDL_GetWindowSurface(window), &(s.position));
        SDL_UpdateWindowSurface(window);


        // if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
        /**SDL_Surface *scren = SDL_CreateRGBSurface(0, 640, 480, 32,
                                        0x00FF0000,
                                        0x0000FF00,
                                        0x000000FF,
                                        0xFF000000);
        SDL_Texture *sdlTexture = SDL_CreateTexture(renderer,
                                                    SDL_PIXELFORMAT_ARGB8888,
                                                    SDL_TEXTUREACCESS_STREAMING,
                                                    630,
                                                    480);


        SDL_UpdateTexture(sdlTexture,
                          NULL,
                          scren->pixels,
                          scren->pitch);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,
                       sdlTexture,
                       NULL,
                       NULL);
*/
        while (not input.finished()) {/**
            content.back() = {i,j,1,1};*/
            ++j;
            update();
        }
        destroy();
        return 0;
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
/**

namespace sdl {
    SDL_Window* window(0);
    SDL_Renderer *renderer = 0;
    vector<surface> content;
    Input input;
    void init(string title) {
        atexit(SDL_Quit);
        if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            cerr << "Error dith SDL : " << SDL_GetError() << endl;
            SDL_Quit();
            exit(-1);
        }
        SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer); // SDL_WINDOW_SHOWN|SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC,&win,&ren);
 /*
        window = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  800,
                                  600,
                                  SDL_WINDOW_SHOWN);
        ///canvas =
        ///SDL_FillRect(canvas, NULL, SDL_MapRGB(canvas->format, 17, 206, 112));
    }
    void hide() {
        SDL_HideWindow(window);
    }
    void show() {
        SDL_ShowWindow(window);
    }
    void destroy() {/**
        for(auto s : content)
            SDL_FreeSurface(s.content);
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
    void update() {
        /**for(auto s : content) {
            SDL_SetRenderDrawColor(s.renderer, 255, 255, 0, 255);///, NULL, SDL_GetWindowSurface(window), &(s.position));
            SDL_RenderClear(s.renderer);
            SDL_RenderPresent(s.renderer);
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        ///SDL_UpdateWindowSurface(window);
    }

    int Main(){
        content.push_back({});
        SDL_SetRenderDrawColor(content.back().renderer, 255, 255, 0, 255);
        init();
        ///Input::showCursor(false);
        ///SDL_GetTicks();
        /**
        for(auto s : content)
            SDL_BlitSurface(s.content, NULL, SDL_GetWindowSurface(window), &(s.position));
        SDL_UpdateWindowSurface(window);


        // if all this hex scares you, check out SDL_PixelFormatEnumToMasks()!
        /**SDL_Surface *scren = SDL_CreateRGBSurface(0, 640, 480, 32,
                                        0x00FF0000,
                                        0x0000FF00,
                                        0x000000FF,
                                        0xFF000000);
        SDL_Texture *sdlTexture = SDL_CreateTexture(renderer,
                                                    SDL_PIXELFORMAT_ARGB8888,
                                                    SDL_TEXTUREACCESS_STREAMING,
                                                    630,
                                                    480);


        SDL_UpdateTexture(sdlTexture,
                          NULL,
                          scren->pixels,
                          scren->pitch);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,
                       sdlTexture,
                       NULL,
                       NULL);

        SDL_RenderPresent(renderer);


        while (not input.finished()) {
            update();
        }
        destroy();
        return 0;
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

        SDL_SetRenderDrawColor(renderer, i/2, j, i*j, 255);
        SDL_RenderDrawPoint(renderer, i, j);
*/
