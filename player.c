#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "object.h"
#include "player.h"
#include "packice.h"


PlayerBoard *board_create()
{
	PlayerBoard *board = malloc(sizeof(PlayerBoard));
	board->nbPlayer = 0;
	return board;
}

void board_destroy(PlayerBoard *board)
{
	int size = board->nbPlayer;
	if (size >= 1)
	{
		for (int i = 0 ; i<size; i++)
		{
			player_destroy(&board->listPlayer[i]);
		}
		free(board->listPlayer);
	}
	free(board);	
}

void addPlayer(Player new, PlayerBoard *board)
{
	int size = board->nbPlayer;
	if(size >= 0 && size < 4)
	{
		if (size == 0)
		{
			board->listPlayer = malloc(sizeof(Player));
		}
		else 
		{
			board->listPlayer = realloc(board->listPlayer, (size + 1) * sizeof(Player));
			
		}
		board->listPlayer[size] = new;
		board->nbPlayer++;
		printf("%d\n",board->nbPlayer);
	}
}


Player getPlayerById(int id, PlayerBoard *board)
{
	int size = board->nbPlayer;
	for(int i = 0; i<size; i++)
	{
		Player player = board->listPlayer[i];
		if (player.id == id)
		{
			return player; 
		}
	}
	return player_create(-1, "notfound", "blanc"); //Pas génial
}


Player getPlayerByIndex(int index, PlayerBoard *board)
{
	return board->listPlayer[index];
}


void deletePlayer(Player delete, PlayerBoard *board)
{
	int size = board->nbPlayer;
	for(int i = 0; i<size; i++)
	{
		if(board->listPlayer[i].id == delete.id)
		{
			if (i<size-1)
			{
				Player tmp = board->listPlayer[i+1];
				board->listPlayer[i+1] = board->listPlayer[i];
				board->listPlayer[i] = tmp;
			}
		}
	}
	player_destroy(&board->listPlayer[size-1]);
	board->listPlayer = realloc(board->listPlayer, (size - 1) * sizeof(Player));
	board->nbPlayer--;
}

Player player_create(int id, char *name, char *color)
{
	Player newP;

	Position pos = {0, 0};
	Vector vect = {0, 0};
	Stat score = {0, 0 ,0};
	

	newP.id = id;
	newP.pos = pos;
	newP.vect = vect;
	newP.score = score;

	newP.name = malloc(strlen(name)+1 * sizeof(char));
	newP.color = malloc(strlen(color)+1 * sizeof(char));
	strcpy(newP.name, name);
	strcpy(newP.color, color);
	
	return newP;
}


void player_destroy(Player *p)
{
	free(p->name);
	free(p->color);
}

void addScoreTravelled(Player *player, int value)
{
	player->score.nb_travelled += value;
}

void addScoreIcecube(Player *player, int value)
{
	player->score.nb_icecube += value;
}

void addScoreKilling(Player *player, int value)
{
	player->score.killing += value;
}


