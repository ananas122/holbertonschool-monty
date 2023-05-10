#include "monty.h"

/**
 * _token - splits a string into tokens
 * @line: input string
 * @delimiter: delimiter character
 * Return: array of tokens
 */
char **_token(char *line, char *delimiter)
{
        char **tokens = NULL;
        char *token = NULL;
        int i = 0;
        const int token_size = 100;

        tokens = malloc(sizeof(char *) * token_size);
        if (tokens == NULL)
                return (NULL);

        token = strtok(line, delimiter);
        while (token != NULL)
        {
                tokens[i] = token;

		printf("%s\n", token);

		i++;

                token = strtok(NULL, delimiter);
        }
        tokens[i] = NULL;
        return (tokens);
}
