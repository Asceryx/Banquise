#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#include "../object.h"
#include "../player.h"
#include "../packice.h"
#include "../game.h"
#include "../display.h"



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

int main () 
{
	srand(time (NULL));
	PackIce Banquise = packice_create(SIZE);
	printf("Taille : %d\n", Banquise.size);
	init_position_departure_arrive(&Banquise);
	



	Player p1 = player_create(1, "Toto", "Bleu");
	Player p2 = player_create(2, "Tata", "Rouge");
	Player p3 = player_create(3, "Tutu", "Vert");
	Player p4 = player_create(4, "Titi", "Bleu");

	printf("Création du board\n");
	PlayerBoard *board = board_create();

	printf("Création du board fait\n");
	addPlayer(p1, board);
	printf("Ajout p1\n");

	addPlayer(p2, board);
	printf("Ajout p2\n");

	addPlayer(p3, board);
	printf("Ajout p3\n");

	addPlayer(p4, board);
	printf("Ajout p4\n");

	init_position_players(&Banquise, board);

	show(Banquise);

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
	printf(" position de départ %d;%d\n", Banquise.departure.x, Banquise.departure.y);
	printf(" position de arrivé %d;%d\n", Banquise.arrive.x, Banquise.arrive.y);

	packice_destroy(Banquise);
	return EXIT_SUCCESS;
}