/** @file   "jeu.cpp"
 *  @brief  Contain jeu(), in all namespaces
 */
#include "jeu.h"
/**
                                           ╔══════╗
                                           ║ Game ║
                                           ╚══════╝
Actual score is:        2
╔═════╦═════╦═════╦═════╗
║  0  ║  0  ║  0  ║  0  ║
╠═════╬═════╬═════╬═════╣
║  0  ║  0  ║  0  ║  0  ║
╠═════╬═════╬═════╬═════╣
║  0  ║  0  ║  0  ║  0  ║
╠═════╬═════╬═════╬═════╣
║  0  ║  0  ║  0  ║  2  ║
╚═════╩═════╩═════╩═════╝

*/

namespace cmd {
    void jeu (void) {
        affichage::resizeScreen(SCREEN_WIDTH,SCREEN_HEIGHT);
        affichage::setTitle("Game");
        Grille grille(grilleVide());

        while(1) {
            grille = addNumber(grille);
            grille = deplacement(grille,GAUCHE);
            setPos(0,3);

            cout << "Actual score is:\t" << score(grille) << endl;

            afficheGrille(grille);
            exit(0);
        }
    }
}
namespace opengl {
    void jeu (void) {

    }
}
namespace sdl {
    void jeu (void) {

    }
}
