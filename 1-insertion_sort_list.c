#include "sort.h"


/**
 * swap_nodes - swap the nodes
 * @current: The current pointer to the list
 * @list: The list
 */

void swap_nodes(listint_t *current, listint_t **list)
{
	listint_t *first, *next_f, *prev_f, *two, *next_two, *prev_two = NULL;

	first = current;
	two = current->next;
	next_f = first->next;
	if (first->prev)
		prev_f = first->prev;
	else
		prev_f = NULL;
	if (two->next)
		next_two = two->next;
	else
		next_two = NULL;
	prev_two = two->prev;
	if (prev_f)
		prev_f->next = next_f;
	else
		*list = two;
	if (next_two)
		next_two->prev = prev_two;
	first->next = next_two;
	first->prev = two;
	two->next = first;
	two->prev = prev_f;
}

/**
 * insertion_sort_list - implement the insertion sort method
 * @list: The list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *already, *current;
	int aux = 0, aux_2 = 0;

	if (!list)
		return;
	already = *list;
	while (already->next)
	{
		if (already->n > already->next->n)
		{
			swap_nodes(already, list);
			print_list(*list);
			aux = 1;
			current = already->prev;

			while (current->prev)
			{
				if (current->prev->n > current->n)
				{
					swap_nodes(current->prev, list);
					print_list(*list);
					aux_2 = 1;
				}
				else
					break;
				if (!aux_2)
					current = current->prev;
				aux_2 = 0;
			}
		}
		if (!aux)
		already = already->next;
		aux = 0;
	}
}
