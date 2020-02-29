#include <stdio.h>
#include <stdlib.h>

#include "../packice.h"
#include "../display.h"

#define SIZE 5

int main () {


	PackIce Banquise = create(SIZE);
	show(Banquise);
	setBlockLiquid(Banquise, 2 , 3);
	show(Banquise);

	//destroy(&Banquise);
	return EXIT_SUCCESS;
}