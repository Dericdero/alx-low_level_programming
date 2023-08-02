#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @q: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *q)
{
	size_t num = 0;

	while (q)
	{
		num++;
		q = q->next;
	}

	return (num);
}
