#include "main.h"
/**
 * main - Entry point of the simple shell
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 * Return: Exit status
 */
int main(int argc, char **argv, char **env)
{
	char *input = NULL, *path = NULL;
	size_t size = 0;
	char *tokens[20], *paths[20];
	int exit_status = 0;

	(void)argc;
	(void)argv;

	init_shell(env, &path, paths);

	while (1)
	{
		if (get_user_input(&input, &size) == -1)
		{
			free(input);
			free(path);
			exit(EXIT_SUCCESS);
		}

		display_prompt();

		/* Tokenize user input */
		split_string(input, " \n\t\r", tokens);

		/* Handle user commands */
		exit_status = handle_command(env, &path, paths, tokens);
	}

	return (exit_status);
}
