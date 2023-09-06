#include "main.h"

/**
 * create_file - creates a file
 * @filename: Pointer to the name of the file to be created
 * @text_content: pointer to string to be written in the file
 * Return: -1 if function fails, otherwise return 1
 */

int create_file(const char *filename, char *text_content)
{
	if (filename == NULL)
	{
		return (-1);
	}
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		size_t length = 0;

		while (text_content[length] != '\0')
		{
			length++;
		}

		ssize_t words = write(fd, text_content, length);

		if (words == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
