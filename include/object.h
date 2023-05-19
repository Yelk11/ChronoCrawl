

enum direction{
    UP,
    DOWN,
    RIGHT,
    LEFT
};


typedef struct object{
    char c;
    int x, y;

}object;

object* object_init(char c, int x, int y);
char object_get_char(object* obj);
void object_move(object* obj, enum direction dir);
void object_draw(object* obj);
void object_clear(object* obj);
