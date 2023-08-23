#include "shell.h"

/**
 * free_exit - function that frees and exits all memory allocated
 *
 * @cmd: pointer to the allocated command memory that will be freed
 *
 * Return: void (Nothing)
 */
void free_exit(char **cmd)
{
	size_t n = 0;

	if (cmd == NULL)
		return;

	while (cmd[n])
	{
		free(cmd[n]);
		n++;
	}

	if (cmd[n] == NULL)
		free(cmd[n]);
	free(cmd);
	exit(EXIT_FAILURE);
}

/**
 * free_dp - function that frees all the memory allocated for a command
 *
 * @cmd: pointer to allocated memory
 *
 * Return: void (Nothing)
 */
void free_dp(char **cmd)
{
	size_t n = 0;

	if (cmd == NULL)
		return;

	while (cmd[n])
	{
		free(cmd[n]);
		n++;
	}

	if (cmd[n] == NULL)
		free(cmd[n]);
	free(cmd);
}
