#include "grille.h"

Grille grilleVide () {
    return Grille(GRILL_HEIGHT,Ligne(GRILL_WIDTH,0));
}

Grille initialiseGrille (Grille grille) {
    for(auto& lines : grille)
        for(auto& cases : lines)
            cases = 0;
    return grille;                                              /**< Don't forget to do this even if it's a non-sense (can run faster by using & */
}

Grille deplacementGauche(Grille grille) {

    for(unsigned int y = 0; y < grille.size(); ++y)
        for(unsigned int x = 0; x < grille.at(y).size(); ++x)
        /**< Looking for each case in the grill */
            for(unsigned int z = 0; z < x; ++z) {
            /**< Looking for each case before selected */
                int& oldC(grille.at(y).at(x));      /**< Used to simplify a little bit the code */
                int& newC(grille.at(y).at(z));      /**<  */
                if(newC == 0) {
                    newC = oldC;
                    oldC = 0;
                }
                else if(newC == oldC) {
                    oldC = 0;
                    newC = newC*2;
                }
            }
    return grille;
}
Grille deplacementDroite(Grille grille) {
    for(unsigned int x = 0; x < grille.at(0).size(); ++x) {
        for(unsigned int y = 0; y < grille.size(); ++y) {
                ///Look at all cases down
                int& oldC(grille[y].at(x));
                int& newC(oldC);
                for(unsigned int z = grille.at(0).size()-1; z > x; z--) {
                    int& oldC(newC);
                    int& newC(grille[y].at(z));
                    if(newC == 0) {
                        newC = oldC;
                        oldC = 0;
                    }
                    else if(newC == oldC) {
                        oldC = 0;
                        newC = newC*2;
                    }
                }
            }
        }
    return grille;
}
Grille deplacementBas(Grille grille) {
    for(unsigned int x = 0; x < grille.at(0).size(); ++x) {
        for(unsigned int k = 0; k < grille.size(); ++k) {
            for(unsigned int y = 0; y < grille.size() - 1; ++y) {
                if(grille[y + 1][x] == grille[y][x]) {
                    grille[y + 1][x]+=grille[y][x];
                    grille[y][x] = 0;
                }
                else if(grille[y + 1][x] == 0) {
                    grille[y + 1][x]+=grille[y][x];
                    grille[y][x] = 0;
                }
            }
        }
    }
    return grille;
}
Grille deplacementHaut(Grille grille) {

    for(unsigned int x = 0; x < grille.at(0).size(); ++x) {
        for(unsigned int k = 0; k < grille.size(); ++k) {
            for(unsigned int y = 1; y < grille.size(); ++y) {
                if(grille[y - 1][x] == grille[y][x]) {
                    grille[y - 1][x]+=grille[y][x];
                    grille[y][x] = 0;
                }
                else if(grille[y - 1][x] == 0) {
                    grille[y - 1][x]+=grille[y][x];
                    grille[y][x] = 0;
                }
            }
        }
    }
    return grille;
}

bool estTerminer(Grille grille) {
    for(unsigned int y = 0; y < grille.size(); ++y)
        for(unsigned int x = 0; x < grille.at(y).size(); ++x)
            if(grille[y][x] == 0)
                return false;
    for(unsigned int y = 0; y < grille.size() - 1; ++y)
        for(unsigned int x = 1; x < grille.at(y).size()- 1; ++x)
            if(grille[y][x] == grille[y+1][x]
            or grille[y][x] == grille[y][x+1])
                return false;
    return true;
}

Grille addNumber(Grille g) {
    int compt(0), alea(0);
    srand(time(NULL));
    for(auto lines : g)
        for(auto cases : lines)
            if(!cases)
                ++compt;
    if(compt) {
        alea = ((compt * rand()) / RAND_MAX);
        for(auto& lines : g)
            for(auto& cases : lines) {
                if(!cases) {
                    if(alea)
                        --alea;
                    else {
                        cases = 2;
                        return g;
                    }
                }
            }
    }
    return g;
}

bool estGagnant(Grille grille) {
    #warning Function non implemented
    #warning Test not deployed
    #warning No commented
    return true;
}
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
            exit(1);
    }
}

int score( Grille grille ) {
    int score(0);
    for(auto& lines : grille)
        for(auto& cases : lines)
            score+=cases;
    return score;
}
