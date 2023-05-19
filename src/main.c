#include <ncurses.h>
#include "object.h"
#include "map.h"
int main(void)
{
    // int row, col;
    initscr();
    noecho(); // dont echo what keys are pressed
    keypad(stdscr,TRUE); // enable function keys (arrow keys)
    curs_set(0); // set curser invisible


    // initialise map
    map_draw();

    // initialise characters
    object* player = object_init('@', 5, 5);

    refresh();

    
    int c = 0;
    while ((27 != (c = getch()))) // 27 == ESC
    {
        mvaddch('g',2,2);
        refresh();
        if (KEY_UP == c)
            object_move(player, UP);
        if (KEY_DOWN == c)
            object_move(player, DOWN);
        if (KEY_RIGHT == c)
            object_move(player, RIGHT);
        if (KEY_LEFT == c)
            object_move(player, LEFT);

        // draw player
        map_draw();
        object_draw(player);

        refresh();
    }

    endwin();

    return 1;
}