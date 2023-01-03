#include "sort.h"

/**
 * swaping - swap nodes of the current node and next or prev depending
 * of his evaluation, if next is greater than current or prev is less than
 * current
 * @head: current node position
 * @list: list to sort
 * @order: Number that defines validation of prev or next node with the current
 */
void swaping(listint_t **head, listint_t **list, int order)
{
	listint_t *current, *next, *prev, *link;

	current = *head;
	prev = current->prev;
	next = current->next;
	if (order == 1)
	{
		link = prev->prev;
		current->next = prev;
		current->prev = link;
		prev->next = next;
		next->prev = prev;
		prev->prev = current;
		if (link)
			link->next = current;
	}
	else
	{
		link = next->next;
		current->next = link;
		current->prev = next;
		if (prev)
			prev->next = next;
		next->prev = prev;
		next->next = current;
		if (link)
			link->prev = current;
	}
	if (current->prev == NULL)
		*list = current;
	if (order == 1)
		current = current->next;
	else
		current = current->prev;
	print_list(*list);
	*head = current;
}

/**
 * cocktail_sort_list - function that sorts a linked list using coctail
 * @list: pointer to first node in linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int i = 1;

	if (list == NULL || *list == NULL)
		return;

	while (i != 0)
	{
		i = 0;
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swaping(&head, list, 0);
				i++;
			}
		}
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swaping(&head, list, 1);
				i++;
			}
		}
	}
}
