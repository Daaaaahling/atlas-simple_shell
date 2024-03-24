#include "main.h"
/**
 * handle_command - Handle user commands
 * @env: environment variables
 * @path: pointer to the PATH variable
 * @paths: array storing PATH directories
 * @tokens: array storing tokenized input
 * Return: exit status
 */
int handle_command(char **env, char **path, char **paths, char **tokens)
{
	int exit_status = 0;
	int i;

	if (!tokens[0])
	{
		/* Empty input, return 0 as exit status */
		return (0);

	if (strcmp(tokens[0], "exit") == 0)
	
		free(*path);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(tokens[0], "env") == 0)
	{
		/* Display environment variables */
		for (i = 0; env[i] != NULL; i++)
		{
			write(STDOUT_FILENO, env[i], strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		/* Return 0 as exit status */
		return (0);
	}
	if (access(tokens[0], X_OK) == 0)
		run_child(*path, tokens[0], tokens);
	else
		exit_status = search_and_execute(*path, paths, tokens);

	return (exit_status);
}
