/** @file   "jeu.cpp"
 *  @brief  Contain jeu(), in all namespaces
 */
#include "jeu.h"
/** zdsq    Actual score is:        2086
╔═════╦═════╦═════╦═════╗
║  2  ║  8  ║  4  ║ 16  ║
╠═════╬═════╬═════╬═════╣
║1024 ║ 128 ║ 512 ║  2  ║
╠═════╬═════╬═════╬═════╣
║  8  ║ 256 ║ 16  ║ 64  ║
╠═════╬═════╬═════╬═════╣
║  2  ║ 32  ║  8  ║  4  ║
╚═════╩═════╩═════╩═════╝
*/
/** zqsd    Actual score is:        1124
╔═════╦═════╦═════╦═════╗
║  8  ║  4  ║  2  ║ 128 ║
╠═════╬═════╬═════╬═════╣
║ 32  ║ 512 ║ 64  ║  2  ║
╠═════╬═════╬═════╬═════╣
║  2  ║ 64  ║  4  ║ 32  ║
╠═════╬═════╬═════╬═════╣
║ 256 ║  2  ║  8  ║  4  ║
╚═════╩═════╩═════╩═════╝

*/
/** sqzd    Actual score is:        1800
╔═════╦═════╦═════╦═════╗
║  0  ║  2  ║  8  ║  4  ║
╠═════╬═════╬═════╬═════╣
║ 512 ║ 64  ║ 32  ║1024 ║
╠═════╬═════╬═════╬═════╣
║  0  ║ 128 ║  4  ║ 16  ║
╠═════╬═════╬═════╬═════╣
║  2  ║  0  ║  0  ║  4  ║
╚═════╩═════╩═════╩═════╝

*/
/** dsqz    Actual score is:        3640 Win
╔═════╦═════╦═════╦═════╗
║  8  ║ 64  ║  2  ║  4  ║
╠═════╬═════╬═════╬═════╣
║ 32  ║ 128 ║2048 ║  8  ║
╠═════╬═════╬═════╬═════╣
║ 16  ║  4  ║ 32  ║1024 ║
╠═════╬═════╬═════╬═════╣
║  2  ║ 256 ║  4  ║  8  ║
╚═════╩═════╩═════╩═════╝

*/

namespace cmd {
    void jeu (void) {
        affichage::resizeScreen(SCREEN_WIDTH,SCREEN_HEIGHT);
        affichage::setTitle("Game");
        affichage::cursor(true);
        Grille grille(grilleVide()), grilleO;

        while(1) {
            grille = addNumber(grille);
            grilleO = grille;
            setPos(0,3);

            cout << "Actual score is:\t" << score(grille) << endl;

            afficheGrille(grille);

            do {
                grille = deplacement(grille,getMove());
            }while(grilleO == grille);

            if(estTerminer(grille))
                if(estGagnant(grille))
                    if(_getch() == 'q')
                        exit(5346);
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
