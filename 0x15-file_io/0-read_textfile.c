#include <stdio.h>
#include "main.h"

/**
 * read_textfile - reads a textfile and printd it onto the POSIX stdout.
 * @filename: textfile being read
 * @letters: no of letters to be read
 *
 * Return: the number of letters read and prinnted
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd;
	ssize_t words;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	t = read(fd, buff, letters);
	words = write(STDOUT_FILENO, buff, t);

	free(buff);
	close(fd);
	return (words);
}

