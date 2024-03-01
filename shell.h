#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 50

void run_shell(void);
void execute_command(char *command);
void execute_external_command(char *command, char **args);
void handle_exit_command(void);
void handle_env_command(void);
void print_environment(void);

#endif  /* SHELL_H */
