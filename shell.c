#include "shell.h"

int main(void)
{
	char **args;
	char *command;
	char *cmd_cpy;

	command = print_prompt();
	cmd_cpy = strdup(command);

	args = _strtok(cmd_cpy, " ");
	int pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			fprintf(stderr, "hsh: command not found");
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
