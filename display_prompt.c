#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * display_prompt - Check if stdin/ standard input stream is connected to
 * terminal and prompt if it is.
 * If not connected, set flag to break loop.
 *
 * Returns: 0 if stdin is connected to a terminal or
 * 1 if stdin is not connected to a terminal.
 */
int display_prompt(void)
{
	/* Check if stdin is connected to a terminal */
	if (isatty(STDIN_FILENO))
		printf("$ "); /* Print prompt if connected to a terminal */
	else
		return (1); /* Set flag to break loop if not connected */
	return (0); /* Success */
}
