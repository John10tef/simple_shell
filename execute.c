#include "shell.h"

/**
 * execute_external_command - Executes an external command.
 * @command: The command to execute.
 * @args: The arguments for the command.
 *
 * Return: void.
 */
void execute_external_command(char *command, char **args)
{
	int pid = fork();

	if (pid < 0)
	{
		fprintf(stderr, "Fork error\n");
		return;
	}
	else if (pid == 0)
	{
		execvp(command, args);
		fprintf(stderr, "%s: not found\n", command);
		exit(1);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}
