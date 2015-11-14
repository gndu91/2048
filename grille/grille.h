#include <vector>
#include <iostream>
#include <cstdlib>

#ifndef MINC
    #define MINC
    #include "../main.h"
#endif // MINC


Grille grilleVide () {
    return Grille(GRILL_HEIGHT,Ligne(GRILL_WIDTH,0));
}
Grille initialiseGrille ( Grille grille ) {return grille;}
Grille deplacementGauche( Grille grille ) {return grille;}
Grille deplacementDroite( Grille grille ) {return grille;}
Grille deplacementHaut( Grille grille ) {return grille;}
Grille deplacementBas( Grille grille ) {return grille;}

/** Documentation a faire **/
Grille deplacement( Grille grille , int direction ) {
    switch ( direction ) {
        case GAUCHE:
            return deplacementGauche( grille );
        case DROITE:
            return deplacementDroite( grille );
        case HAUT:
            return deplacementHaut( grille );
        case BAS:
            return deplacementBas( grille );
        default:
            cerr << "Deplacement␣non−autorise !" << endl ;
            exit(-1);
    }
}
bool estTerminer( Grille grille ) {return true;}
int score( Grille grille ) {return -1;}
bool estGagnant( Grille grille ) {return false;}
