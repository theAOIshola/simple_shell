#include "shell.c"

/**
 * getPath - get env value from environment variable PATH
 * @env: pointer to the env variable
 * Return: paths to commands
 */

char **getPath(char **env)
{
	char *var = NULL;
	char **path = NULL;
	size_t i = 0;

	var = strtok(env[i], "=");
	while (env[i] != NULL)
	{
		if (_strcmp(var, "PATH"))
		{
			var = strtok(NULL, "\n");
			path = _strtok(var, ":");
			return (path);
		}
		i++;
		var = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * error_message(char *name, int cyc, char **cmd)
 *
 */

void error_message(char *name, int cyc, char *first_cmd)
{
	char m;

	m = cyc + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, first_cmd, _strlen(first_cmd));
	write(STDOUT_FILENO, ": not found\n", 12);
}

/**
 * print_env - print all environment variables
 * @env: pointer to the environment variables
 * Return: Nothing
 */

void print_env(char **env)
{
	size_t n = 0, len;

	while (env[n])
	{
		len = _strlen(env[n]);
		write(STDOUT_FILENO, env[n], len);
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
}

/**
 * exec_cmd - execute any command
 * @cmd: tokenized command
 * @name: name of the shell
 * @env: pointer to the array of environment variables
 * @cyc: count of executed cycles
 * Return: Nothing.
 */

void exec_cmd(char **cmd, char *name, char **env, int cyc)
{
	char **path = NULL, *full_path = NULL;
	struct stat status;
	unsigned int i = 0;

	if (_strcmp(cmd[0], "env") != 0)
		print_env(env);
	if (stat(cmd[0], &status) == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror(name);
			free_exit(cmd);
		}
	}
	else
	{
		path = getPath(env);
		while (path[i])
		{
			full_path = _strcat(path[i], cmd[0]);
			i++;
			if (stat(full_path, &status) == 0)
			{
				if (execve(full_path, cmd, env) == -1)
				{
					perror(name);
					free_dp(path);
					free_exit(cmd);
				}
				return;
			}
		}
		error_message(name, cyc, cmd[0]);
		free_dp(path);
	}
}
