#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*out;

	if (*begin_list)
	{
		out = ft_create_elem(data);
		out->next = *begin_list;
		*begin_list = out;
	}
	else
		*begin_list = ft_create_elem(data);
}
/*
#include <stdio.h>

void display(t_list *d)
{
	while (d != NULL)
	{
		printf("[%d] ", d->data);
		d = d->next;
	}
}

int main()
{
	t_list *head;

	head = (t_list*)malloc(sizeof(t_list));
	head = NULL;
	int a = 1;
	int b = 2;
	int c = 3;
	void *i = &a;
	void *j = &b;
	void *x = &c;
	ft_list_push_front(&head, i);
	ft_list_push_front(&head, j);
	ft_list_push_front(&head, x);
	display(head);
}*/
