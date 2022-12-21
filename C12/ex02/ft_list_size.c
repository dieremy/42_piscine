#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != NULL)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

/*#include <stdio.h>
t_list	*ft_create_elem(void *data)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

void display(t_list *n)
{
	while (n != NULL)
	{
		printf("[%d] ", (int*)n->data);
		n = n->next;
	}
	printf("\n"); 
}

int main()
{
	t_list *head = NULL;
	int a = 1;
	int b = 2;
	int c = 3;
	void *i = &a;
	void *j = &b;
	void *x = &c;

	head = (t_list*)malloc(sizeof(t_list));
	head = ft_create_elem(i);
	head->next = ft_create_elem(j);
	head->next->next = ft_create_elem(x);
	display(head);
	printf("size of head = %d\n", ft_list_size(head));
}*/
