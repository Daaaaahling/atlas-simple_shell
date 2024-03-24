#include "main.h"
/**
 * get_user_input - Get input from the user
 * @input: pointer to store the input string
 * @size: pointer to store the size of the input string
 * Return: 0 on success, -1 on failure
 */
int get_user_input(char **input, size_t *size)
{
	if (getline(input, size, stdin) == -1)
		return (-1);
	return (0);
}
