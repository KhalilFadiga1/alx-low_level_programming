#include <stdlib.h>

/**
 * init_dog - initialise a variable of type struct dog
 * @d: pointer to type struct dog
 * @name:  name to the dog
 * @age: age of dog
 * @owner: owner of dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
