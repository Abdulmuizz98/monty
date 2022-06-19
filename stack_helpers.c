#include "monty.h"
/**
 * add_dnodeint - adds a new node at beginning of a list.
 * @head: the pointer to the head of the list
 * @n: the value of the new node
 *
 * Return: if success - the address of the new element;
 * otherwise - NULL;
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	/*create the new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new_node->n = n;
	if (*head) /* if head is not null */
	{
		/*make heads prev point to the new node*/
		(*head)->prev = new_node;
		/*make new node next point to head.*/
		new_node->next = *head;
	}
	/*change head to new node*/
	*head = new_node;
	return (*head);
}
/**
 * add_dnodeint_end - adds a new node at the end of a list.
 * @head: the pointer to the head of the list
 * @n: the value of the new node
 *
 * Return: if success - the address of the new element;
 * otherwise - NULL;
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *trav;

	trav = *head;
	/*create the new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	new_node->n = n;
	if (*head) /* if head is not null */
	{
		/*traverse to the end of the list*/
		while ((trav)->next != NULL)
		{
			trav = (trav)->next;
		}
		/*set last element next to new node*/
		trav->next = new_node;
		/*set new node prev to last element*/
		new_node->prev = trav;
	}
	else
	{
		/*change head to new node*/
		*head = new_node;
	}
	return (new_node);
}
/**
 * print_list - prints all the elements of a stack_t list.
 * @h: the pointer to the head of the list
 *
 * Return: the number of nodes in the list.
 */
size_t print_list(const stack_t *h)
{
	const stack_t *trav = h;
	int count = 0;

	while (trav)
	{
		printf("%d\n", trav->n);
		trav = trav->next;
		count++;
	}
	return (count);
}

