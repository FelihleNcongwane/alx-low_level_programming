#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - returns -1.
 *         If the file does not exist or the user lacks write permissions - returns -1.
 *         Otherwise, returns 1 on success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
    int o, w, len = 0;

    /* Check if filename is NULL */
    if (filename == NULL)
        return (-1);

    /* Calculate the length of the text_content string */
    if (text_content != NULL)
    {
        for (len = 0; text_content[len];)
            len++;
    }

    /* Open the file for writing, appending if it exists */
    o = open(filename, O_WRONLY | O_APPEND);

    /* Write the content of text_content to the end of the file */
    w = write(o, text_content, len);

    /* Check for errors in file opening or writing */
    if (o == -1 || w == -1)
        return (-1);

    /* Close the file */
    close(o);

    /* Return 1 on success */
    return (1);
}
