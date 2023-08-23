#include "shell.h"

/**
<<<<<<< HEAD
 * get_child_process - create a child process that executes
 * a command in shell
 * @cmd: command inputed into shell
 * @name: name of the shell
 * @env: array of environment variables
 * @cyc: number of cycles run
 * Return: Nothing.
=======
 * get_child_process - function that handles sub (child) processes
 * @cmd: pointer to command that will be tokenized
 * @name: pointer to the name of the shell
 * @env: pointer to the enviroment variables
 * @cyc: executed cycles count
 *
 * Return: Nothing
>>>>>>> Henshaw
 */
void get_child_process(char **cmd, char *name, char **env, int cyc)
{
	int pid, exit_status, wait_status;

	pid = fork();

	if (pid < 0)
	{
		perror("Error: ");
		free_exit(cmd);
	}
	else if (pid == 0)
	{
		execve(cmd[0], name, env, cyc);
		free_dp(cmd);
	}
	else
	{
		wait_status = waitpid(pid, &exit_status, 0);
		if (wait_status < 0)
			free_exit(cmd);
		free_dp(cmd);
	}
}

/**
<<<<<<< HEAD
 * change_directory - change the directory of the process
 * @path: new path to change to
 * Return: 1 on Success, 98 on error.
=======
 * change_directory - function that changes the working directory
 * @path: the new current working dir
 * Return: 0 on success otherwise -1 is returned.
>>>>>>> Henshaw
 */

int change_directory(char *path)
{
	char *tmp = NULL;
	size_t size = 1024;

	if (!path)
		path = getcwd(tmp, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
