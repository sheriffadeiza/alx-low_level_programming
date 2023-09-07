#include "main.h"
#include <stdlib.h>

/**
 * read_textfile-text file print read to STDOUT.
 * @filename: text file is read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *ch;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ch  = malloc(sizeof(char) * letters);
	t = read(fd, ch, letters);
	w = write(STDOUT_FILENO, ch, t);

	free(ch);
	close(fd);
	return (w);
}
