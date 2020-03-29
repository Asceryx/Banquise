#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "object.h"
#include "player.h"
#include "packice.h"



PackIce packice_create(int size)
{
	PackIce p;
	p.surface = malloc(size * sizeof(Ice));
	for (int i = 0; i<size; i++)
	{
		p.surface[i] = malloc(size * sizeof(Ice));
		for (int j = 0; j<size; j++)
		{
			Ice new_block = createBlock();
			p.surface[i][j] = new_block;
		}
	}
	Position pos = {0,0};
	p.departure = pos;
	p.arrive = pos;
	p.size = size;
	return p;
}

Ice createBlock()
{
	Ice block;
	block.is_water = false;
	block.occuped_by = NULL;
	block.on_it = NULL;
	block.is_departure = false;
	block.is_arrive = false;
	return block;
}


Ice getBlock(PackIce packice, int x, int y)
{
	return packice.surface[x][y];
}

void packice_destroy(PackIce packice)
{
	int max_size = packice.size;
	for (int i = 0; i<max_size; i++)
	{
		free(packice.surface[i]);
	}
	free(packice.surface);
	packice.size = 0;
}

void setBlockWater(PackIce packice, int x, int y)
{
	packice.surface[x][y].is_water=true;
}

void setSwitchIceWater(PackIce packice, int x, int y)
{
	packice.surface[x][y].is_water=!packice.surface[x][y].is_water;
}

void setBlockDeparture(PackIce *packice, int x, int y)
{
	if (packice->surface[x][y].is_arrive == false)
	{
		packice->surface[x][y].is_departure=true;
		Position pos = {x,y};
		packice->departure = pos;
	}
	else
	{
		setBlockDeparture(packice, (x+1) % packice->size, (y+1) % packice->size);
	}	
}


void setBlockArrive(PackIce *packice, int x, int y)
{
	if (packice->surface[x][y].is_departure == false)
	{
		packice->surface[x][y].is_arrive=true;
		Position pos = {x,y};
		packice->arrive = pos;
	}
	else
	{
		setBlockArrive(packice, (x+1) % packice->size, (y+1) % packice->size);
	}	
}

bool setPlayer(PackIce *packice, Player player, int x, int y)
{
	int dx = (x+1) % packice->size;
	int dy = (y+1) % packice->size;;
	if(packice->surface[x][y].occuped_by == NULL && packice->surface[x][y].is_arrive==false && packice->surface[x][y].is_departure==false)
	{
		packice->surface[x][y].occuped_by = malloc(sizeof(Player));
		packice->surface[x][y].occuped_by = &player;
		return true;
	}
	else if packice->surface[dx][y].occuped_by != NULL{
		return setPlayer(packice, player,  dx, y) || setPlayer(packice, player,  x, dy);
	}

}


