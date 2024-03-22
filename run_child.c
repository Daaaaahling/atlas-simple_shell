#include "main.h"

/**
 * run_child - Executes a command in a child process.
 * @path_env: The PATH environment variable (freed in function).
 * @command_path: Full path of the command to execute.
 * @command_args: Arguments of the command.
 *
 * Description: This function creates a child process using fork(), and in 
 * child process, executes the specified command using execve().
 * If execution fails, the child process exits with failure status.
 * In the parent process, it waits for the
 * child process to complete and returns the exit status of  executed command.
 *
 * Return: Exit status of command
 */
int run_child(char *path_env, char *command_path, char **command_args)
{
	pid_t child_pid;
	pid_t wait_status;
	int exit_status = 0;

	/* Free the dynamically allocated memory for the PATH variable */
	free(path_env);

	/* Create a child process using fork() */
	child_pid = fork();

	if (child_pid == 0)
	{
		/* In child process, execute the command */
		if (execve(command_path, command_args, NULL) == -1)
			exit(EXIT_FAILURE); /* Exit if execution fails */
	}
	else if (child_pid < 0)
	{
		exit(EXIT_FAILURE); /* Exit the parent process if fork fails */
	}
	else
	{
		/* In parent process, wait for child process to complete */
		do {
			wait_status = waitpid(child_pid, &exit_status, WUNTRACED);
		} while (!WIFEXITED(exit_status) && !WIFSIGNALED(exit_status));
	}
	/* Ignore the wait_status variable to prevent compiler warnings */
	(void) wait_status;

	/* Return the exit status of the executed command */
	return (exit_status);
}
