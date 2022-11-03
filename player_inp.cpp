//
//
//

#include "player_inp.h"
#include <conio.h>

void player_inp(bool* quit, int* p_x, int* p_y, bool* gen, int* level) { //TODO pievienot mainīgo kas pasaka vai spēlētājs ir jaunā istabā, vai pārvietojas pa savu istabu
#define KEY_UP 119 //72
#define KEY_DOWN 115 //80
#define KEY_LEFT 97 //75
#define KEY_RIGHT 100 //77
#define KEY_CLOSE 27

        switch(getch()) {
            case KEY_UP: {
                if (*p_x -1 != 0 || (*p_x - 1 == 0 && *p_y == 10))
                    *p_x -= 1;
                break;
            }
            case KEY_DOWN: {
                if (*p_x +1 != 20)
                    *p_x += 1;
                break;
            }
            case KEY_LEFT:
                if (*p_y -1 != 0) {
                    *p_y -= 1;
                break;
            }
            case KEY_RIGHT: {
                if (*p_y +1 != 20)
                    *p_y += 1;
                break;
            }
            case KEY_CLOSE: {
                *quit = true;
                break;
            }
        }
        if (*p_x == 0 && *p_y == 10) {
            *gen = true;
            *level += 1;
            *p_x = 19;
            *p_y = 11;
        }
};