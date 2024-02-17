#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its content to STDOUT.
 * @filename: The name of the text file being read.
 * @letters: The number of letters to be read and printed.
 *
 * Return: The actual number of bytes read and printed (w),
 *         0 when the function fails or the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buf;
    ssize_t fd, w, t;

    /* Open the file for reading */
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    /* Allocate memory for the buffer */
    buf = malloc(sizeof(char) * letters);

    /* Read 'letters' number of bytes from the file into the buffer */
    t = read(fd, buf, letters);

    /* Write the content of the buffer to STDOUT */
    w = write(STDOUT_FILENO, buf, t);

    /* Free the allocated memory for the buffer */
    free(buf);

    /* Close the file */
    close(fd);

    /* Return the actual number of bytes read and printed */
    return (w);
}
