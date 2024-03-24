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

	if (!tokens[0])
		return (0);

	if (strcmp(tokens[0], "exit") == 0)
	{
		free(*path);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(tokens[0], "env") == 0)
	{
		display_env(env);
		return (0);
	}
	if (access(tokens[0], X_OK) == 0)
		run_child(*path, tokens[0], tokens);
	else
		exit_status = search_and_execute(*path, paths, tokens);

	return (exit_status);
}
