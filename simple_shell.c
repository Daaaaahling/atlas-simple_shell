#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
    char input[100];

	while (1) /* infinite loop */
	{
        if (display_prompt() == 1)
		{
			printf("Error: Not connected to terminal\n");
			break;
			}
			fgets(input, sizeof(input), stdin); /* Read user input */

		/* Remove trailing newline character if present */
		if (input[strlen(input) - 1] == '\n')
			input[strlen(input) - 1] = '\0';

        execute_command(input);
    }

    return 0;
}
