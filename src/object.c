#include "object.h"
#include <ncurses.h>
#include <stdlib.h>

object* object_init(char c, int x, int y){
    object* obj = calloc(1, sizeof(struct object));;
    obj->c = c;
    obj->x = x;
    obj->y = y;
    return obj;
}

char object_get_char(object* obj){
    return obj->c;
}

void object_move(object* obj, enum direction dir){
    object_clear(obj);
    switch(dir){
        case UP:
            obj->x--;
            break;
        case DOWN:
            obj->x++;
            break;
        case RIGHT:
            obj->y++;
            break;
        case LEFT:
            obj->y--;
            break;
    }
}

void object_draw(object* obj){
    mvaddch(obj->x, obj->y,'@');
}

void object_clear(object* obj){
    mvdelch(obj->x,obj->y);
}





