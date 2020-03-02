#ifndef PLAYER_H
#define PLAYER_H


typedef struct Player Player;
typedef struct Stat Stat;
typedef struct PlayerBoard PlayerBoard;

struct Stat {
	int nb_travelled;
	int nb_icecube;
	int killing;
};



struct Player {
	int id;
	char *name;
	char *color;
	Position pos;
	Vector vect;
	Stat score;
};


struct PlayerBoard 
{
	int nbPlayer;
	Player *listPlayer;
};


PlayerBoard *board_create();
void board_destroy(PlayerBoard *board);

Player player_create(int id, char *name, char *color);
void player_destroy(Player *p);

Player getPlayerById(int id, PlayerBoard *board);
Player getPlayerByIndex(int index, PlayerBoard *board);
void addPlayer(Player new, PlayerBoard *board);
void deletePlayer(Player delete, PlayerBoard *board);


void addScoreTravelled(Player *player, int value);
void addScoreIcecube(Player *player, int value);
void addScoreKilling(Player *player, int value);
Stat getScore(Player player);

void trap(Player player);

bool isAlive(Player player);
bool isWinner(Player player);


#endif