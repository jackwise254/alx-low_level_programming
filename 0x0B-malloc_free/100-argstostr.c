#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program.
 * @ac: argument count.
 * @av: pointer to arguments.
 *
 * Return: pointer to the new string, or NULL if failure.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, total_len = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	// Calculate total length of the new string
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			total_len++;
			j++;
		}
		total_len++;  // for '\n'
	}

	str = (char *)malloc(total_len + 1); // +1 for the terminating NULL byte
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			str[k] = av[i][j];
			k++;
			j++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';  // Null terminate the concatenated string

	return (str);
}
