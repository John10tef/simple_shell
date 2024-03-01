#include "shell.h"

/**
 * print_environment - Prints the current environment variables.
 *
 * Return: void.
 */
void print_environment(void)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

/**
 * execute_command - Executes a command.
 * @command: The command to execute.
 *
 * Return: void.
 */
void execute_command(char *command)
{
	char *args[MAX_ARGUMENTS + 1];
	char *token = strtok(command, " ");
	int i = 0;
	char path_command[MAX_COMMAND_LENGTH];
	char *path_env;


	while (token != NULL && i < MAX_ARGUMENTS)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (args[0] != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
		{
			handle_exit_command();
			return;
		}

		if (strcmp(args[0], "env") == 0)
		{
			handle_env_command();
			return;
		}

		path_env = getenv("PATH");
		if (path_env != NULL)
		{
			token = strtok(path_env, ":");

			while (token != NULL)
			{
				snprintf(path_command, sizeof(path_command), "%s/%s", token, args[0]);

				if (access(path_command, X_OK) == 0)
				{
					execute_external_command(path_command, args);
					return;
				}

				token = strtok(NULL, ":");
			}
		}

		fprintf(stderr, "%s: not found\n", args[0]);
	}
}

/**
 * run_shell - Runs the shell.
 *
 * Return: void.
 */
void run_shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	char prompt[] = "($) ";

	while (1)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

		if (read(STDIN_FILENO, command, sizeof(command)) == 0)
		{
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		execute_command(command);
	}
}
