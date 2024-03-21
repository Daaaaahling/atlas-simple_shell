#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void execute_command(char *command)
{
	if (strcmp(command, "quit") == 0)
	{
		printf("Exiting the interpreter.\n");
		exit(0);
	}
	else
	{
		printf("Command not recognized: %s\n", command);
	}
}