#ifndef OBJECT_H
#define OBJECT_H

#include "packice.h"

typedef struct Icecube Icecube;
typedef struct Rock Rock;
typedef struct Spring Spring;
typedef struct Hammer Hammer;
typedef struct Trap Trap;

struct Icecube {
	Position *pos;
	Vector *vec;
};

struct Rock {
	Position *pos;
};

struct Spring {
	Position *pos;
};

struct Hammer {
	Position *pos;
};

struct Trap {
	Position *pos;
};


void create(void *object);

Position move(Icecube ice);
void effect(void *object);



#endif