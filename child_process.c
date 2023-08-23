#include "shell.h"

/**
 * get_child_process - create a child process that executes
 * a command in shell
 * @cmd: command inputed into shell
 * @name: name of the shell
 * @env: array of environment variables
 * @cyc: number of cycles run
 * Return: Nothing.
 */

void get_child_process(char **cmd, char *name, char **env, int cyc)
{
	int pid, exit_status, wait_status;

	pid = fork();

	if (pid < 0)
	{
		perror("Error: ");
		/*FREE_EXIT(cmd)*/
	}
	else if (pid == 0)
	{
		execve(cmd[0], name, env, cyc);
		/*FREE(cmd)*/
	}
	else
	{
		wait_status = waitpid(pid, &exit_status, 0);
		if (wait_status < 0)
			/*FREE_EXIT(cmd)*/
		/*FREE(cmd)*/
	}
}

/**
 * change_directory - change the directory of the process
 * @path: new path to change to
 * Return: 1 on Success, 98 on error.
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
