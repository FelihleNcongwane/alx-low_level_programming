#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reading text file and print to STDOUT.
 * @filename: Text file to read.
 * @letters: Maximum number of letters to read.
 * Return w - Actual number of bytes read and printed.
 *        and 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buf;
    ssize_t fd;
    ssize_t w;
    ssize_t t;

    // Check if filename is NULL
    if (filename == NULL) {
        return (0);
    }

    // Open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return (0);
    }

    // Allocate memory for the buffer
    buf = malloc(sizeof(char) * letters);
    if (buf == NULL) {
        close(fd);
        return (0);
    }

    // Read the file into the buffer
    t = read(fd, buf, letters);
    if (t <= 0) {
        free(buf);
        close(fd);
        return (0);
    }

    // Print the contents of the buffer to STDOUT
    w = write(STDOUT_FILENO, buf, t);

    // Free the buffer and close the file
    free(buf);
    close(fd);

    return (w);
}
