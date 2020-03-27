#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "object.h"
#include "player.h"
#include "packice.h"
#include "game.h"


void init_position_departure_arrive(PackIce *packice)
{
	int size = packice->size;
	int randomLineDepart = rand() % size;
	int randomColumnDepart = rand() % size;

	int randomLineArrive = rand() % size;
	int randomColumnArrive = rand() % size;

	setBlockDeparture(packice, randomLineDepart, randomColumnDepart);
	setBlockArrive(packice, randomLineArrive, randomColumnArrive);
}

void init_position_players(PackIce packice, PlayerBoard *board)
{
	int size = board->nbPlayer;
	Position depart = packice.departure;
	for(int i = 0; i<size; i++)
	{
		Player unpositioned = getPlayerByIndex(i, board);
		setPlayer(packice,unpositioned, depart.x, depart.y);
	}
}


