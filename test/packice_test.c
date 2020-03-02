#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "../object.h"
#include "../player.h"
#include "../packice.h"

#define SIZE 5

static void display_water(Ice block)
{
	if (block.is_water)
	{
		printf("C'est de l'eau !\n");
	}
	else
	{
		printf("Ce n'est pas de l'eau (donc de la glace)\n");
	}
}

int main () {


	PackIce Banquise = packice_create(SIZE);
	printf("%d\n", Banquise.size);

	Ice block = getBlock(Banquise,0 , 0);
	display_water(block);
	setBlockWater(Banquise, 2 , 3);
	Ice modifyblock = getBlock(Banquise, 2, 3);
	display_water(modifyblock);

	setSwitchIceWater(Banquise, 3 , 4);
	Ice switchblock = getBlock(Banquise, 3, 4);
	display_water(switchblock);
	setSwitchIceWater(Banquise, 3 , 4);
	switchblock = getBlock(Banquise, 3, 4);
	display_water(switchblock);

	packice_destroy(Banquise);
	return EXIT_SUCCESS;
}