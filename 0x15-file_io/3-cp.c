#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Allocates a buffer of 1024 bytes.
 *
 * @param file The name of the file the buffer is storing characters for.
 *
 * @return A pointer to the newly-allocated buffer.
 */
char *creates_buffer(char *file)
{
    char *buffer;

    /* Allocate memory for the buffer */
    buffer = malloc(sizeof(char) * 1024);

    /* Check if memory allocation was successful */
    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't write to %s\n", file);
        exit(99);
    }

    return buffer;
}

/**
 * @brief Closes file descriptors.
 *
 * @param fd The file descriptor to be closed.
 */
void close_file(int fd)
{
    int c;

    /* Close the file descriptor */
    c = close(fd);

    /* Check for errors in closing the file descriptor */
    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * @brief Copies the contents of a file to another file.
 *
 * @param argc The number of arguments supplied to the program.
 * @param argv An array of pointers to the arguments.
 *
 * @return 0 on success.
 *
 * @details If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
    int from, to, r, w;
    char *buffer;

    /* Check if the correct number of arguments is provided */
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    /* Allocate a buffer for copying data */
    buffer = creates_buffer(argv[2]);

    /* Open the source file for reading */
    from = open(argv[1], O_RDONLY);
    r = read(from, buffer, 1024);

    /* Open the destination file for writing, creating it if necessary */
    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do
    {
        /* Check for errors in reading from the source file */
        if (from == -1 || r == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Can't read from file %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        /* Write the contents of the buffer to the destination file */
        w = write(to, buffer, r);

        /* Check for errors in writing to the destination file */
        if (to == -1 || w == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Can't write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        /* Read the next portion of data from the source file into the buffer */
        r = read(from, buffer, 1024);

        /* Open the destination file for appending in the next iteration */
        to = open(argv[2], O_WRONLY | O_APPEND);

    } while (r > 0);

    /* Free the allocated buffer and close file descriptors */
    free(buffer);
    close_file(from);
    close_file(to);

    return 0;
}
