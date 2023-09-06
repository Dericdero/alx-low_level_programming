#include <stdio.h>

/**
 * read_textfile - reads a textfile and printd it onto the POSIX stdout.
 * @filename: textfile being read
 * @letters: no of letters to be read
 * Return: the number of letters read and prinnted
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
	{
		return (0);
	}
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}
	char *buff = (char *)malloc(sizeof(char) * (letters + 1));

	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	ssize_t words = read(fd, buff, letters);

	if (words == -1)
	{
		close(fd);
		free(buff);
		return (0);
	}

	buff[words] = '\0';

	ssize_t wordings = write(STDOUT_FILENO, buff, words);

	if (wordings == -1 || (size_t)wordings != words)
	{
		close(fd);
		free(buff);
		return (0);
	}
	close(fd);
	free(buff);
	return (words);
}
