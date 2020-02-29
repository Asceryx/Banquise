#include <stdio.h>
#include <string.h>

#include "packice.h"

typedef struct Player Player;
typedef struct Stat Stat;

struct Stat {
	int nb_travelled;
	int nb_icecube;
	int killing;
};



struct Player {
	int id;
	char *name;
	char *color;
	Position *pos;
	Vector *vect;
	Stat *score;
};




Player create(int id, char *name, char *color);
void destroy(Player *p);

Player getPlayer(int id);
void setPlayer(int id);

Boolean isAlive(int id);
Boolean isWinner(int id);




