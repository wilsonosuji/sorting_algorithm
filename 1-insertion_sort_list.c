#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Doubly linked List to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (!(list == NULL || *list == NULL))
	{
		node = (*list)->next;
		while (node != NULL)
		{
			while (node->prev != NULL && node->n < node->prev->n)
			{
				node->prev->next = node->next;
				if (node->next != NULL)
					node->next->prev = node->prev;
				node->next = node->prev;
				node->prev = node->prev->prev;
				node->next->prev = node;
				if (node->prev != NULL)
					node->prev->next = node;
				else
					*list = node;
				print_list(*list);
			}
			node = node->next;
		}
	}
}
