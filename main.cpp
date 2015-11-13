#include <SDL2/SDL.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#include <iostream>
#include <vector>

using namespace std ;

const int GAUCHE = 7;
const int DROITE = 4;
const int HAUT   = 8;
const int BAS    = 2;

const int GRILL_W=  4;
const int GRILL_H=  4;

typedef vector<vector<int>> Grille  ;
typedef vector<int>         Ligne   ;

Grille grilleVide (){
    return Grille(GRILL_H,Ligne(GRILL_W,0));
}
Grille initialiseGrille ( Grille grille ){return grille;}
Grille deplacementGauche( Grille grille ){return grille;}
Grille deplacementDroite( Grille grille ){return grille;}
Grille deplacementHaut( Grille grille ){return grille;}
Grille deplacementBas( Grille grille ){return grille;}

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
bool estTerminer( Grille grille ){return true;}
int score( Grille grille ){return -1;}
bool estGagnant( Grille grille ){return false;}
void afficheGrille ( Grille g){}
void jeu (void){}

int main(int, char*[]) {
    return 0;
}
