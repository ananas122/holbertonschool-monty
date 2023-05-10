#include "monty.h"

/**
 * read_textfile - Reads texte file and prints it
 * @filename: Le fichier à lire et afficher
 * @letters: la taille du fichier, son nombre de character
 *
 * Return: le nombre de lettre lu et l'affiche
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t openFile, readFile, writeFile;
	char *buffer;


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
	writeFile = write(STDOUT_FILENO, buffer, readFile);
	if (writeFile == -1 || writeFile != readFile)
	{
		free(buffer);
		close(openFile);
		return (0);
	}

	free(buffer);
	close(openFile);
	return (writeFile);
}
