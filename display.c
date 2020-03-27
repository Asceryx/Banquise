#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "packice.h"




void show(PackIce packice)
{
	int max_size = packice.size;
	for (int i = 0; i<max_size; i++)
	{
		for (int j = 0; j < max_size; j++)
		{
			Ice block = getBlock(packice,i,j);
			if (!(block.is_water)) {
				printf(" |%d : S : " , block.pos->x);
			}
			else {
				printf(" |%d : L : " , block.pos->x);
			}
			printf("%d| " , block.pos->y);
		}
		printf("\n");
	}
}





