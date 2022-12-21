#include "ft_list.h"
#include <stdio.h>

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

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		i++;
	}
	return (NULL);
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
	head = ft_create_elem(a1);
	head->next = ft_create_elem(b2);
	head->next->next = ft_create_elem(c3);
	head->next->next->next = ft_create_elem(d4);
	head->next->next->next->next = ft_create_elem(e5);
	printf("a.[%d]\n", *(int*)ft_list_at(head, 0)->data);
	printf("b.[%d]\n", *(int*)ft_list_at(head, 1)->data);
	printf("c.[%d]\n", *(int*)ft_list_at(head, 2)->data);
	printf("d.[%d]\n", *(int*)ft_list_at(head, 3)->data);
	printf("e.[%d]\n", *(int*)ft_list_at(head, 4)->data);
}