#include "shell.h"

/**
 * handle_exit_command - Handles the built-in exit command.
 *
 * Return: void.
 */
void handle_exit_command(void)
{
	exit(0);
}

/**
 * handle_env_command - Handles the built-in env command.
 *
 * Return: void.
 */
void handle_env_command(void)
{
	print_environment();
}
