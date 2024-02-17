#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Allocates a buffer of 1024 bytes for file operations.
 *
 * @param file The name of the file the buffer is allocated for.
 * @return A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
    char *buffer;

    buffer = malloc(sizeof(char) * 1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO,
                "Error: Unable to allocate buffer for %s\n", file);
        exit(99);
    }

    return (buffer);
}

/**
 * @brief Closes a file descriptor.
 *
 * @param fd The file descriptor to be closed.
 */
void close_file(int fd)
{
    int c;

    c = close(fd);

    if (c == -1)
    {
        dprintf(STDERR_FILENO, "Error: Unable to close fd %d\n", fd);
        exit(100);
    }
}

/**
 * @brief Copies the contents of one file to another.
 *
 * @param argc The number of arguments supplied to the program.
 * @param argv An array of pointers to the arguments.
 * @return 0 on success.
 *
 * @details If the argument count is incorrect - exit code 97.
 *          If the source file does not exist or cannot be read - exit code 98.
 *          If the destination file cannot be created or written to - exit code 99.
 *          If there are issues reading from or writing to the files - exit code 100.
 */
int main(int argc, char *argv[])
{
    int from, to, r, w;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    buffer = create_buffer(argv[2]);
    from = open(argv[1], O_RDONLY);
    r = read(from, buffer, 1024);
    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    do
    {
        if (from == -1 || r == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Unable to read from file %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        w = write(to, buffer, r);
        if (to == -1 || w == -1)
        {
            dprintf(STDERR_FILENO,
                    "Error: Unable to write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

        r = read(from, buffer, 1024);
        to = open(argv[2], O_WRONLY | O_APPEND);

    } while (r > 0);

    free(buffer);
    close_file(from);
    close_file(to);

    return (0);
}
