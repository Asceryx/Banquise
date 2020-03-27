#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "../object.h"


int main () {
	Object *o_icecube = create_icecube_object(2,3);
	Icecube *item = object_to_item(o_icecube);
	printf("%d", item->pos.x);


	printf("%s\n", o_icecube->type);
	Icecube *po = (Icecube *)o_icecube->content;
	printf("%d : %d\n", po->pos.x, po->pos.y);

	Object *o_hammer = create_hammer_object(3,4);
	printf("%s\n", o_hammer->type);
	Hammer *ph = (Hammer *)o_hammer->content;
	printf("rotation : %d\n", ph->rotation);
	printf("%d : %d\n", ph->pos.x, ph->pos.y);
}