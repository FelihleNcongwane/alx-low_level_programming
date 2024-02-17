#include "main.h"

/**
 * create_file - Creates a file and writes text to it.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails to create the file or write to it - returns -1.
 *         Otherwise, returns 1 on success.
 */
int create_file(const char *filename, char *text_content)
{
    int fd, w, len = 0;

    /* Check if filename is NULL */
    if (filename == NULL)
        return (-1);

    /* Calculate the length of the text_content string */
    if (text_content != NULL)
    {
        for (len = 0; text_content[len];)
            len++;
    }

    /* Open the file for creating, writing, and truncating if it exists */
    fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

    /* Write the content of text_content to the file */
    w = write(fd, text_content, len);

    /* Check for errors in file creation or writing */
    if (fd == -1 || w == -1)
        return (-1);

    /* Close the file */
    close(fd);

    /* Return 1 on success */
    return (1);
}
