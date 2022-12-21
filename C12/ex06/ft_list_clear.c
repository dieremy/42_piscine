#include "ft_list.h"
#include <stdio.h>

void	ft_free(void *data)
{
	printf("%d\n", *(int*)data);
	free(data);
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	while (begin_list)
	{
		(*free_fct)(begin_list->data);
		begin_list = begin_list->next;
	}
	free(begin_list);
}

void	display(t_list *n)
{
	while (n)
	{
		printf("[%s]\n", n->data);
		n = n->next;
	}
}

int main()
{
	t_list	*head;
	t_list	info1;
	t_list	info2;
	t_list	info3;

	head = &info1;
	info1.next = &info2;
	info2.next = &info3;
	info3.next = NULL;

	info1.data = "hello";
	info2.data = "my";
	info3.data = "friend";
	display(head);
	printf("\nREMOVED\n");
	ft_list_clear(head, &ft_free);
	display(head);
}