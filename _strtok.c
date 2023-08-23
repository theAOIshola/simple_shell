#include "shell.h"

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

	tokenArr = malloc(sizeof(char *) * (_strlen(str) + 1));
	if (tokenArr == NULL)
		return (NULL);

	token = strtok(str, delim);

	while (token != NULL)
	{
		tokenArr[i] = malloc(_strlen(token) + 1);
		{
			free_dp(tokenArr);
			return (NULL);
		}

		_strcpy(tokenArr[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	tokenArr[i] = NULL;

	return (tokenArr);
}
