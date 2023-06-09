#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 *
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: On success, 1.
 *         On failure, -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_written, text_len = 0;

	switch ((filename == NULL) || ((text_content != NULL) && (text_content[0] == '\0')))
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

	fd = open(filename, O_WRONLY | O_APPEND);
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
