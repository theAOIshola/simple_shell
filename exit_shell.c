#include "shell.h"

/**
 * exit_shell - exits the shell
 * @cmd - pointer to command
 * Return: Nothing
 */

void exit_shell(char **cmd)
{
	int mode = 0;

	if (cmd[1] == NULL)
	{
		free_dp(cmd);
		exit(EXIT_SUCCESS);
	}

	mode = _atoi(cmd[1]);
	free_dp(cmd);
	exit(mode);
}
