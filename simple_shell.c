#include "main.h"

/**
 * simple_shell - Entry point of the simple shell.
 * @argc: Argument count.
 * @argv: Argument vector.
 * @env: Environment variables.
 * Return: Exit status.
 */
int simple_shell(int argc, char **argv, char **env)
{
	char *input = NULL, *path = NULL;
	size_t size = 0;
	char *tokens[20], *paths[20];
	int exit_status = 0, i;

	/* Suppress unused variable warnings */
	(void)argc;
	(void)argv;

	/* Main loop for the shell */
	while (1)
	{
		i = 0;

		/* Find the PATH variable in environment variables */
		while (env[i] != NULL)
		{
			if (strncmp(env[i], "PATH=", 5) == 0)
			{
				/* Copy the PATH variable value */
				path = copy_string((env[i] + 5));
				break;
			}
			i++;
		}
		/* Split the PATH variable value into individual directories */
		split_string(path, ":", paths);

		/* Display prompt */
		if (display_prompt() != 0)
		{
			break; /* Break loop if not connected to a terminal */
		}

		/* Get user input */
		if (getline(&input, &size, stdin) == -1)
		{
			/* Handle end of file condition */
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		/* Tokenize user input */
		split_string(input, " \n\t\r", tokens);
		
		/* Check for built-in commands or external commands */
		if (!tokens[0])
		{
			free(path);
			continue; /* Empty input, continue to next iteration */
		}
		if (strcmp(tokens[0], "exit") == 0)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(tokens[0], "env") == 0)
		{
			for (i = 0; env[i] != NULL; i++)
			{
				write(STDOUT_FILENO, env[i], strlen(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(path);
			continue;
		}
		
		if (access(tokens[0], X_OK) == 0)
			run_child(path, tokens[0], tokens);
		else
			exit_status = search_and_execute(path, paths, tokens);
	}
	return (exit_status);
}
