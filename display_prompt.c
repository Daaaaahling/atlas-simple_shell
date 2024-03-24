#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * display_prompt - Check if stdin/ standard input stream is connected to
 * terminal and prompt if it is.
 *
 * Return: void
 */
int display_prompt(void)
{
	/* Check if stdin is connected to a terminal */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "SHELL $ ", 8);
}
