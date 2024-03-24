#include "main.h"

/**
 * display_prompt - Check if stdin/ standard input stream is connected to
 * terminal and prompt if it is.
 *
 * Return: void
 */
void display_prompt(void)
{
	/* Check if stdin is connected to a terminal */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "SHELL $ ", 8);
}
