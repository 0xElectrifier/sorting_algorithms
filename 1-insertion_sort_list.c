#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *			order using the `insertion sort` algorithm
 * @list: pointer to head of list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp, *forward;

	if (list == NULL || (*list)->next == NULL)
		return;

	forward = (*list)->next;
	while (forward != NULL)
	{
		curr = forward;
		forward = forward->next;

		while (curr->prev != NULL && curr->n < (curr->prev)->n)
		{
			temp = curr->prev;
			if (temp->prev != NULL)
				temp->prev->next = curr;
			if (curr->next != NULL)
				curr->next->prev = temp;
			temp->next = curr->next;
			curr->next = temp;
			curr->prev = temp->prev;
			temp->prev = curr;

			if (curr->next == (*list) && curr->n < (*list)->n)
				*list = curr;

			print_list(*list);
		}
	}
}
