#include "main.h"

/**
 * append_text_to_file - text is appended to the end of the file.
 * @filename: A pointer to the name of the file.
 * @text_content: add the string to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, wtof, cont = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (cont = 0; text_content[cont];)
			cont++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	wtof = write(o, text_content, cont);

	if (o == -1 || wtof == -1)
		return (-1);

	close(o);

	return (1);
}
