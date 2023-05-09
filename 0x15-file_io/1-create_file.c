#include "main.h"

/**
 * create_file - Creates a new file.
 *
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: On success, 1.
 *         On failure, -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, bytes_written, text_len = 0;
	switch (filename == NULL || (text_content && text_content[0] == '\0'))
	{
		case 1:
			return (-1);
		default:
			break;
	}

	if (text_content != NULL)
	{
		while (text_content[text_len])
			text_len++;
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	bytes_written = write(fd, text_content, text_len);
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
