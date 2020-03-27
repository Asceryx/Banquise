#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "object.h"



static Object *create_object(void *item, char *name_type) 
{
	Object *object = malloc(sizeof(Object));
	object->type = malloc((strlen(name_type) + 1) * sizeof(char));
	object->content = malloc(sizeof(&item));
	strcpy(object->type, name_type);
	memcpy(object->content, item, sizeof(&item));
	return object;
}

Icecube create_icecube(int init_x, int init_y) 
{
	Icecube icecube;
	Position pos = {init_x, init_y};
	Vector vect = {0, 0};
	icecube.pos = pos;
	icecube.vect = vect;
	return icecube;
}


Object *create_icecube_object(int init_x, int init_y)
{
	Icecube icecube = create_icecube(init_x, init_y);
	void *item = &icecube;
	Object *object = create_object(item, "icecube");
	return object;
}


Rock create_rock(int init_x, int init_y)
{
	Rock rock;
	Position pos = {init_x, init_y};
	rock.pos = pos;
	return rock;
}

Object *create_rock_object(int init_x, int init_y)
{
	Rock rock = create_rock(init_x, init_y);
	void *item = &rock;
	Object *object = create_object(item, "rock");
	return object;
}


Spring create_spring(int init_x, int init_y)
{
	Spring spring;
	Position pos = {init_x, init_y};
	spring.pos = pos;
	return spring;
}

Object *create_spring_object(int init_x, int init_y)
{
	Spring spring = create_spring(init_x,init_y);
	void *item = &spring;
	Object *object = create_object(item, "spring");
	return object;
}

Hammer create_hammer(int init_x, int init_y)
{
	Hammer hammer;
	Position pos = {init_x, init_y};
	hammer.pos = pos;
	hammer.rotation = 0;
	return hammer;
}

Object *create_hammer_object(int init_x, int init_y)
{
	Hammer hammer = create_hammer(init_x,init_y);
	void *item = &hammer;
	Object *object = create_object(item, "hammer");
	return object;
}

Trap create_trap(int init_x, int init_y)
{
	Trap trap;
	Position pos = {init_x, init_y};
	trap.pos = pos;
	return trap;
}

Object *create_trap_object(int init_x, int init_y)
{
	Trap trap = create_trap(init_x,init_y);
	void *item = &trap;
	Object *object = create_object(item, "trap");
	return object;
}


void *object_to_item(Object *object)
{
	void *item = NULL;

	if (strcmp(object->type, "icecube") == 0)
	{
		item = malloc(sizeof(Icecube));
		Icecube *value = (Icecube *)object->content;
		*((Icecube *)item) = *value;
	}
	else if(strcmp(object->type, "rock") == 0)
	{
		item = malloc(sizeof(Rock));
		Rock *value = (Rock *)object->content;
		*((Rock *)item) = *value;
	}
	else if(strcmp(object->type, "spring") == 0)
	{
		item = malloc(sizeof(Spring));
		Spring *value = (Spring *)object->content;
		*((Spring *)item) = *value;
	}
	else if(strcmp(object->type, "hammer") == 0)
	{
		item = malloc(sizeof(Hammer));
		Hammer *value = (Hammer *)object->content;
		*((Hammer *)item) = *value;
	}
	else if(strcmp(object->type, "trap") == 0)
	{
		item = malloc(sizeof(Trap));
		Trap *value = (Trap *)object->content;
		*((Trap *)item) = *value;
	}
	return item;
}