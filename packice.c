#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "packice.h"




PackIce create(int size)
{
	PackIce *p =  malloc(sizeof(PackIce));
	p->surface = malloc(size * sizeof(Ice));
	for (int i = 0; i<size; i++)
	{
		p->surface[i] = malloc(size * sizeof(Ice));
		for (int j = 0; j<size; j++)
		{
			Ice new_block = createBlock(i, j, NULL);
			p->surface[i][j] = new_block;
		}
	}
	p->packsize = size; 
	return *p;
}

Ice createBlock(int x, int y, void *object)
{
	Ice *block =  malloc (sizeof(Ice));
	block->pos = malloc(sizeof(Position));
	(block->pos)->x= x;
	(block->pos)->y= y;
	block->on_it = object;
	block->is_water = false;
	return *block;
}


Ice getBlock(PackIce packice, int x, int y)
{
	return packice.surface[x][y];
}

void destroyBlock(PackIce *packice, int x, int y)
{
	
	free(&packice->surface[x][y].pos);
	packice->surface[x][y].pos = NULL;

	free(&packice->surface[x][y].on_it);
	packice->surface[x][y].on_it = NULL;


	free(&packice->surface[x][y]);
}


void destroy(PackIce *packice)
{
	int max_size = packice->packsize;
	for (int i = 0; i<max_size; i++)
	{
		for(int j = 0; j<max_size; j++)
		{
			destroyBlock(packice, i, j);
		}
	}
	packice->packsize = 0;
	free(packice->surface);
	free(packice);
}

void setBlockLiquid(PackIce packice, int x, int y)
{
	packice.surface[x][y].is_water=true;
}
