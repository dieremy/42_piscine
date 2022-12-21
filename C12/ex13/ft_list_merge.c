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

void	display(t_list *n)
{
	while (n)
	{
		printf("%s\n", n->data);
		n = n->next;
	}
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*out;

	if (begin_list1 == 0 || *begin_list1 == 0)
		*begin_list1 = begin_list2;
	else
	{
		out = *begin_list1;
		while (out->next)
			out = out->next;
		out->next = begin_list2;
	}
}

int main()
{
	t_list *head = ft_create_elem("hello");
	head->next = ft_create_elem("friend");
	t_list *new = ft_create_elem("how you doing?");
	display(head);
	ft_list_merge(&head, new);
	printf("\n########_MERGED_LIST_########\n\n");
	display(head);
}