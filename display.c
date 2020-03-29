#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "object.h"
#include "player.h"
#include "packice.h"




void show(PackIce packice)
{
	int max_size = packice.size;
	printf("%d\n", max_size);
	for (int i=0; i<max_size; i++){
		for(int j=0; j<max_size; j++){
			Ice block = getBlock(packice, i, j);
			if (block.is_water) {
				printf("| W ");
			} 
			else if (block.is_departure) {
				printf("| D ");
			}
			else if (block.is_arrive) {
				printf("| A ");
			}

			else if (block.occuped_by != NULL){
				printf("| P ");
			}
			else {
				printf("| I ");
			}


		}
		printf("|\n");
	}
}





