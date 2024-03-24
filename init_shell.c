#include "main.h"
/**
 * init_shell - Initialize the shell environment
 * @env: environment variables
 * @path: pointer to store the PATH variable
 * @paths: array to store PATH directories
 */
void init_shell(char **env, char **path, char **paths)
{
	int i = 0;

	while (env[i] != NULL)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			*path = copy_string((env[i] + 5));
			break;
		}
		i++;
	}
	split_string(path, ":", paths);
}
