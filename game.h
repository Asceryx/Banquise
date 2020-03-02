#ifndef GAME_H
#define GAME_H

void init_position_departure_arrive(Packice *packice);
void init_position_players(Packice packice, PlayerBoard *board);

void globalWarming(Packice packice);
Boolean pathFinding(Packice packice);
Boolean isWinnable(Packice packice);

#endif