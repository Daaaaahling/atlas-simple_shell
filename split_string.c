#include "main.h"

/**
 * split_string - Splits a string into tokens using specified delimiters.
 * @string: The string to tokenize.
 * @delimiters: The delimiters used for tokenization.
 * @tokens: Array to store the tokens.
 * 
 * Description: This function tokenizes the input string using the provided
 * delimiters and stores the tokens in the specified array.
 *
 * Return: void
 */
void split_string(char *string, char *delimiters, char **tokens)
{
	/* Get the first token in the string */
	char *token = strtok(string, delimiters);
	/* Initialize index to track position in the 'tokens' array */
	int index = 0;
	
	/* Continue tokenizing until there are no more tokens */
	while (token != NULL)
	{
		/* Store the current token in the 'tokens' array */
		tokens[index] = token;
		/* Move to the next index in the 'tokens' array */
		index++;
		/* Use strtok with NULL to get the next token in the string */
		token = strtok(NULL, delimiters);
	}
	/* Set last element of tokens array to NULL to indicate end of array */
	tokens[index] = NULL;
}
