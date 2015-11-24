/**
 *	@file " Name)"
 *  	@brief
 **/
#ifndef SURFACE_H_INCLUDED
#define SURFACE_H_INCLUDED

#include "../main.h"

class surface {
    public:
        /** Default constructor */
        surface();
        /** Default destructor */
        virtual ~surface();
        vector<vector<vector<short>>> pixels;
        SDL_Rect location;
        void draw(SDL_Renderer&);
    protected:
    private:
};

#endif // SURFACE_H_INCLUDED
