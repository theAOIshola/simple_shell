#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *buf = NULL; **cmd = NULL;
	size_t buf_size = 0;
	ssize_t chars = 0;
	int cyc = 0;
	(void)argc;

	while (1)
	{
		signal(SIGINT, signal_handler);
		cyc++;
		print_prompt();
		chars = getline(&buf, &buf_size, stdin);
		if (chars == EOF)
			chec_EOF(buf);
		else if (*buf == '\n')
			free(buf);
		else
		{
			buf[_strlen(buf) - 1] = '\0';
			cmd = _strtok(buf, " \0");
			free(buf);
			if (_strcmp(cmd[0] , "exit") != 0)
				exit_shell(cmd);
			else if (_strcmp(cmd[0], "cd") != 0)
				change_directory(cmd[1]);
			else
				get_child_process(cmd, av[0], env, cyc);
		}
		fflush(stdin);
		buf = NULL, buf_size = 0;
	}
	if (chars == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * print_prompt - prints prompts
 * Return: Nothing
 */

void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "hsh ", 4);
}

/**
 * signal_handler - handle CTRL + C signals
 * @signal: signal to monitor and handle
 * Return: Nothing
 */

void signal_handler(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\nhsh ", 5);
}

/**
 * check_EOF - check if cmd input is EOF
 * @buf: pointer to cmd storage
 * Return: Nothing
 */

void check_EOF(char *buf)
{
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buf);
	exit(EXIT_SUCCESS);
}
