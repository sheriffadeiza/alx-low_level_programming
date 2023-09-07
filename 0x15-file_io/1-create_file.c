#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: - -1  If the function fails.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, wtof, cont = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (cont  = 0; text_content[cont];)
			cont++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wtof  = write(fd, text_content, cont);

	if (fd == -1 || wtof == -1)
		return (-1);

	close(fd);

	return (1);
}
