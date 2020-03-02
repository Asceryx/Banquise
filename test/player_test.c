#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../object.h"
#include "../player.h"
#include "../packice.h"


int main () {
	printf("Création du joueur\n");

	Player p1 = player_create(1, "Toto", "Bleu");
	Player p2 = player_create(2, "Tata", "Rouge");
	Player p3 = player_create(3, "Tutu", "Vert");

	printf("Création du board\n");
	PlayerBoard *board = board_create();

	printf("Création du board fait\n");
	addPlayer(p1, board);
	printf("Ajout p1\n");

	addPlayer(p2, board);
	printf("Ajout p2\n");

	printf("%d\n",board->nbPlayer );
	for(int i=0; i<board->nbPlayer; i++)
	{
		printf("================================\n");
		printf("%s\n", board->listPlayer[i].name);
		printf("%s\n", board->listPlayer[i].color);
		printf("================================\n\n");
	}

	addPlayer(p3, board);
	printf("Ajout p3\n");

	deletePlayer(p1, board);
	printf("Suppression p1\n");

	for(int i=0; i<board->nbPlayer; i++)
	{
		printf("================================\n");
		printf("%s\n", board->listPlayer[i].name);
		printf("%s\n", board->listPlayer[i].color);
		printf("================================\n\n");
	}

	Player pgetter = getPlayerById(2, board);
	printf("Nom du player getter : %s\n", pgetter.name);
	printf("Score : %d\n", pgetter.score.nb_travelled);
	addScoreTravelled(&pgetter, 3);
	addScoreTravelled(&pgetter, 3);
	printf("Score : %d\n", pgetter.score.nb_travelled);
	
	
	board_destroy(board);
	return EXIT_SUCCESS;
}