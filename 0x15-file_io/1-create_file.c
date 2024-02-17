#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	// Check if the filename is null
	if (filename == NULL)
		return (-1);

	// Check if the text content is null
	if (text_content != NULL)
	{
		// Calculate the length of the text content
		for (len = 0; text_content[len];)
			len++;
	}

	// Create the file
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	// Check if the file creation failed
	if (fd == -1 || w == -1)
		return (-1);

	// Close the file
	close(fd);

	// Return success
	return (1);
}
