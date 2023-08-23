#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _strtok - tokenize a string
 * @str: string to tokenize
 * @delim: delimeter to separate string
 *
 * Return: pointer to each word
 */

char **_strtok(char *str, char *delim)
{
	char *token;
	char **tokenArr = NULL;
	int i = 0;

	if (!str)
	{
		return (NULL);
	}

	tokenArr = malloc(sizeof(char *));
	if (tokenArr == NULL)
		return (NULL);

	token = strtok(str, delim);

	while (token != NULL)
	{
		char **temp = realloc(tokenArr, (i + 2) * sizeof(char *));

		if (!temp)
		{
			free(tokenArr);
			return (NULL);
		}

		tokenArr = temp;
		tokenArr[i] = token;
		tokenArr[i + 1] = NULL;

		token = strtok(NULL, delim);
		i++;
	}

	return (tokenArr);
}
