#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - Creates a new dog with name, age, and owner.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the new dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *newDog;
    char *nameCopy, *ownerCopy;

    newDog = malloc(sizeof(dog_t));
    if (!newDog)
        return (NULL);

    nameCopy = strdup(name);
    if (!nameCopy)
    {
        free(newDog);
        return (NULL);
    }

    ownerCopy = strdup(owner);
    if (!ownerCopy)
    {
        free(nameCopy);
        free(newDog);
        return (NULL);
    }

    newDog->name = nameCopy;
    newDog->age = age;
    newDog->owner = ownerCopy;

    return (newDog);
}
