#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}
/*
#include <stdio.h>
void display(t_list *n)
{
	while (n != NULL)
	{
		printf("%d\n", *(int*)n->data);
		n = n->next;
	}
}

int main()
{
	t_list *n;
	int a = 13;
	void *b = &a;
	n = ft_create_elem(b);
	display(n);
}*/