#include "ft_list.h"
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
/*
void	display(t_list *n)
{
	while (n)
	{
		printf("%d\n", n->data);
		n = n->next;
	}
}

void	func(void *n)
{
	*(int*)n += 10;
}

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

int main()
{
	t_list *new = ft_create_elem(new);
	new = ft_create_elem(10);
	new->next = ft_create_elem("33");
	display(new);
	ft_list_foreach(new, &func);
	display(new);
}*/