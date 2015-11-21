#include "../main.h"

Grille grilleVide ();
Grille initialiseGrille ( Grille grille );
Grille deplacementGauche( Grille grille );
Grille deplacementDroite( Grille grille );
Grille deplacementHaut( Grille grille );
Grille deplacementBas( Grille grille );
Grille addNumber(Grille);
Grille deplacement( Grille grille , int direction );
bool estTerminer( Grille grille );
int score( Grille grille );
bool estGagnant( Grille grille );
