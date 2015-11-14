/** @file   "jeu.cpp"
 *  @brief  Contain jeu(), in all namespaces
 */
#include "jeu.h"


namespace cmd {
    void jeu (void) {
        affichage::resizeScreen(SCREEN_WIDTH,SCREEN_HEIGHT);
        affichage::setTitle("Game");
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
