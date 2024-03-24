#include "main.h"

/**
 * copy_string - Creates a duplicate of a string.
 * @original: The string to be duplicated.
 * Return: Pointer to the duplicated string,
 * or NULL if memory allocation fails or if original string is NULL
 *
 * Description: This function duplicates the input string and returns
 * a pointer to the copy.
 */
char *copy_string(char *original)
{
	int index = 0;
	int length = 0;
	char *duplicate;

	/* Check if the original string is NULL */
	if (original == NULL)
		return (NULL);

	/* Calculate the length of the original string */
	while (original[index] != '\0')
	{
		index++;
		length++;
	}
	length++;

	/* Allocate memory for the duplicated string */
	duplicate = malloc(length * sizeof(char));
	/* Check if memory allocation was successful */
	if (duplicate == NULL)
		return (NULL);
	/* Copy the contents of the original string to the duplicate */
	for (index = 0; index < length; index++)
		duplicate[index] = original[index];
	/* Return a pointer to the duplicated string */
	return (duplicate);
}
