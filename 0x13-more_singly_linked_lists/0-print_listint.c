#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * print_listint - prints all the elements of a linked list
 * @q: linked list of type listint_t to print
 * Return: number of nodes
 */

size_t print_listint(const listint_t *q)
{
	size_t num = 0;

	while (q)
	{
		printf("%d\n", q->n);
		num++;
		q = q->next;
	}

	return (num);
}
