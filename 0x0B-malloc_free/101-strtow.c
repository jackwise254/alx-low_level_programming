#include "main.h"
#include <stdlib.h>
/**
 * word_count - Count the number of words in a string
 * @str: The string to count
 *
 * Return: The number of words in the string
 */
int word_count(char *str)
{
	int i = 0, count = 0, new_word = 1;

	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			new_word = 1;
		else if (new_word)
		{
			new_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * allocate_and_fill_word - Allocates memory and fills it with word
 * @str: The string source
 * @len: Length of the word
 *
 * Return: Pointer to the word, or NULL if it fails
 */
char *allocate_and_fill_word(char *str, int len)
{
	int j;
	char *word = malloc(sizeof(char) * (len + 1));
	
	if (!word)
		return (NULL);

	for (j = 0; j < len; j++, str++)
		word[j] = *str;
	word[j] = '\0';

	return (word);
}

/**
 * strtow - Splits a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, l, words_count, k;

	if (!str || !*str)
		return (NULL);

	words_count = word_count(str);
	if (words_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (words_count + 1));
	if (!words)
		return (NULL);

	while (i < words_count && *str)
	{
		while (*str && (*str == ' ' || *str == '\t' || *str == '\n'))
			str++;

		l = 0;
		while (str[l] && str[l] != ' ' && str[l] != '\t' && str[l] != '\n')
			l++;

		words[i] = allocate_and_fill_word(str, l);
		if (!words[i])
		{
			for (k = 0; k < i; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		str += l;
		i++;
	}

	words[i] = NULL;
	return (words);
}
