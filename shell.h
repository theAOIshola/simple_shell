#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char **_strtok(char *str, char *delim);

int _atoi(char *s);

void get_child_process(char **cmd, char *name, chr **env, int cyc);
int change_directory(char *path);

char **getPath(char **env);
void error_message(char *name, int cyc, char **cmd);
void print_env(char **env);
void exec_cmd(char **cmd, char *name, char **env, int cyc);

void exit_shell(char **cmd);

void print_prompt(void);
void signal_handler(int signal);
void check_EOF(char *buf);
#endif
