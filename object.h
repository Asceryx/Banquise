#ifndef OBJECT_H
#define OBJECT_H

typedef struct Object Object;
typedef struct Vector Vector;
typedef struct Position Position;

typedef struct Icecube Icecube;
typedef struct Rock Rock;
typedef struct Spring Spring;
typedef struct Hammer Hammer;
typedef struct Trap Trap;

struct Vector {
	int dx;
	int dy;
};

struct Position {
	int x;
	int y;
};

struct Object {
	char *type;
	void *content;
};

struct Icecube {
	Position pos;
	Vector vect;
};

struct Rock {
	Position pos;
};

struct Spring {
	Position pos;
};

struct Hammer {
	Position pos;
	int rotation;
};

struct Trap {
	Position pos;
};

Icecube create_icecube(int init_x, int init_y);
Rock create_rock(int init_x, int init_y);
Spring create_spring(int init_x, int init_y);
Hammer create_hammer(int init_x, int init_y);
Trap create_trap(int init_x, int init_y);

Object *create_icecube_object(int init_x, int init_y);
Object *create_rock_object(int init_x, int init_y);
Object *create_spring_object(int init_x, int init_y);
Object *create_hammer_object(int init_x, int init_y);
Object *create_trap_object(int init_x, int init_y);
void *object_to_item(Object *object);

#endif