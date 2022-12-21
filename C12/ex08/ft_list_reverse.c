#include "ft_list.h"
#include <stdio.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*out;
	t_list	*next;	
	t_list	*prev;

	out = *begin_list;
	next = NULL;
	prev = NULL;
	while (out)
	{
		next = out->next;
		out->next = prev;
		prev = out;
		out = next;
	}
	*begin_list = prev;
}

void	*ft_create_elem(void *data)
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

void	display_i(t_list *d)
{
	while (d)
	{
		printf("[%d]\n", d->data);
		d = d->next;
	}
}

void	display_c(t_list *d)
{
	int	i;

	i = 1;
	while (d && i)
	{
		printf("[%d.%s]\n", i, d->data);
		d = d->next;
		i++;
	}
}

int main()
{
	int a = 34;
	int b = 54;
	int c = 23;
	int d = 40;
	int e = 95;
	void *a1 = &a;
	void *b2 = &b;
	void *c3 = &c;
	void *d4 = &d;
	void *e5 = &e;

	t_list *head = (t_list*)malloc(sizeof(t_list));
	head = ft_create_elem(a);
	head->next = ft_create_elem(b);
	head->next->next = ft_create_elem(c);
	head->next->next->next = ft_create_elem(d);
	head->next->next->next->next = ft_create_elem(e);
	display_i(head);
	printf("\n##################REVERSE##################\n");
	ft_list_reverse(&head);
	display_i(head);

	printf("\n-------------------------------------------------------\n");

	t_list *node;
	t_list info1;
	t_list info2;
	t_list info3;

	node = &info1;
	info1.next = &info2;
	info2.next = &info3;
	info3.next = NULL;

	info1.data = "hello";
	info2.data = "my";
	info3.data = "friend";
	display_c(node);
	printf("\n#################REVERSE#################\n");
	ft_list_reverse(&node);
	display_c(node);
}