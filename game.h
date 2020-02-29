#ifndef GAME_H
#define GAME_H

#include "packice.h"

void init_departure_arrive(Packice **packice);
void init_move_player(int x, int y);


void globalWarming(Packice **packice);
Boolean pathFinding(Packice **packice);
Boolean isWinnable(Packice **packice);

#endif