#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Read text file and print to STDOUT.
 * @filename: The name of the file being read
 * @letters: The number of letters to read from the file
 *
 * Return: The actual number of bytes read and printed (w),
 *         or 0 when the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fd, bytes_read, bytes_written, total_bytes_written;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
		return (0);

	bytes_read = read(fd, buffer, letters);

	total_bytes_written = 0;
	while (bytes_read > 0 && total_bytes_written < bytes_read)
	{
		bytes_written = write(STDOUT_FILENO, buffer + total_bytes_written,
			bytes_read - total_bytes_written);
		if (bytes_written <= 0)
			break;
		total_bytes_written += bytes_written;
	}

	free(buffer);
	close(fd);

	if (bytes_read < 0 || bytes_written < 0 || total_bytes_written < bytes_read)
		return (0);

	return (total_bytes_written);
}
