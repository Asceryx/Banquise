#ifndef PACKICE_H
#define PACKICE_H

typedef struct Ice Ice;
typedef struct PackIce PackIce;

struct Ice {
	bool is_water;
	Player *occuped_by;
	Object *on_it;
	bool is_departure;
	bool is_arrive;	
};

struct PackIce {
	int size;
	Position departure;
	Position arrive;
	Ice **surface;
};

PackIce packice_create(int size);
Ice createBlock();

void packice_destroy(PackIce packice);

Ice getBlock(PackIce packice, int x, int y);
void setBlockWater(PackIce packice, int x, int y);
void setSwitchIceWater(PackIce packice, int x, int y);
void setBlockDeparture(PackIce *packice, int x, int y);
void setBlockArrive(PackIce *packice, int x, int y);

bool setPlayer(PackIce packice, Player player, int x, int y);

#endif