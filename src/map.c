#include "map.h"
#include "perlin.h"

void map_draw(){
    int row, col;
    getmaxyx(stdscr, col, row);

    for (int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            if(Perlin_Get2d(x,y,.5,10) > .5){
                mvaddch(y,x,'#');
            }else{
                mvaddch(y,x,' ');
            }
        }
    }
}











