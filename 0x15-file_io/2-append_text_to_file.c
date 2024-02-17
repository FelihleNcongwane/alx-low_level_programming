#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist or the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

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

	// Open the file in write mode
	o = open(filename, O_WRONLY | O_APPEND);

	// Check if the file exists and the user has write permissions
	if (o == -1)
		return (-1);

	// Write the text content to the file
	w = write(o, text_content, len);

	// Check if the write operation failed
	if (w == -1)
		return (-1);

	// Close the file
	close(o);

	// Return success
	return (1);
}
