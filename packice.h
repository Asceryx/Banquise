#ifndef PACKICE_H
#define PACKICE_H

#include <stdbool.h>

typedef struct Vector Vector;
typedef struct Position Position;
typedef struct Ice Ice;
typedef struct PackIce PackIce;

struct Vector {
	int dx;
	int dy;
};

struct Position {
	int x;
	int y;
};

struct Ice {
	void *on_it;
	Position *pos;
	bool is_water;
};

struct PackIce {
	int packsize;
	Ice **surface;
};

PackIce create(int size);
Ice createBlock(int x, int y, void *object);

void destroy(PackIce *packice);
void destroyBlock(PackIce *packice,int x, int y);

Ice getBlock(PackIce packice, int x, int y);

void setBlockObject(PackIce packice, int x, int y, void *object);
void setBlockLiquid(PackIce packice, int x, int y);



#endif