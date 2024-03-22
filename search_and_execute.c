#include "main.h"

/**
 * search_and_execute - Searches for a command in the directories
 * and executes it
 * @path_env: The PATH environment variable.
 * @dirs: Directories to search for the command.
 * @args: Arguments of the command.
 * 
 * This function searches for the specified command in each directory
 * listed in the PATH environment variable. If the command is found,
 * it is executed. If the command is not found in any directory,
 * returns exit status 127 (command not found).
 * 
 * Returns: Exit status of the command.
 */
int search_and_execute(char *path_env, char **dirs, char **args)
{
    int idx = 0;
    char *full_path = NULL;
    struct stat file_stat;

    /* Iterate through each directory in the path array */
    while (dirs[idx] != NULL)
    {
        /* Construct full path by concatenating directory and command */
        full_path = malloc(strlen(args[0]) + strlen(dirs[idx]) + 2);
        if (full_path == NULL)
            exit(EXIT_FAILURE);

        strcpy(full_path, dirs[idx]);
        strcat(full_path, "/");
        strcat(full_path, args[0]);

        /* Check if constructed path corresponds to an existing file */
        if (stat(full_path, &file_stat) == 0)
        {
            /* If file exists, execute the command */
            execute_command(path_env, full_path, args);
            free(full_path);
            return (0);
        }
        /* Free dynamically allocated memory for constructed path */
        free(full_path);
        /* Move to the next directory in the path array */
        idx++;
    }
    /* If command is not found in any directory, return exit status 127 */
    return (127); /* command not found */
}
