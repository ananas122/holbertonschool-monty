#include "monty.h"

/**
 * readTextFile - Reads texte file and prints it
 * @filename: Le fichier à lire et afficher
 * @letters: la taille du fichier, son nombre de character
 *
 * Return: Le texte file tokenisé
 */

char **readTextFile(const char *filename, size_t letters)
{
	ssize_t openFile, readFile;
	char *buffer;
	char **tokenBuffer;
	int i, lign = 0;

	if (!filename)
		return (0);

	openFile = open(filename, O_RDONLY);
	if (openFile == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
		return (0);

	readFile = read(openFile, buffer, letters);
	if (buffer == NULL)
	{
		free(buffer);
		close(openFile);
		return (0);
	}
	
	buffer[readFile] = '\0';
	tokenBuffer = _token(buffer, "\n");
	
	for (i = 0; tokenBuffer[i]; i++)
		lign++;

	printf("%d\n", lign);

	for (i = 0; i < lign; i++)
		{
			_token(tokenBuffer[i], " ");
		}

	free(buffer);
	close(openFile);

	return (tokenBuffer);
}
