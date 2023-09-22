#include "monty.h"
/**
 * f_pstr - this func prints a string starting at the top of a stack
 * @head: stack head
 * @counter: line number
 * Return: none
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
