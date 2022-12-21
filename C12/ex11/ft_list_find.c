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

int	ft_cmp(void *d1, void *d2)
{
	return ((int*)d1 - (int*)d2);
}

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return (list_ptr);
		list_ptr = list_ptr->next;
	}
	return (NULL);
}

void	display(t_list *n)
{
	while (n)
	{
		printf("%s\n", n->data);
		n = n->next;
	}
}

int main()
{
	t_list *head = ft_create_elem("hello");
	head->next = ft_create_elem("friend");
	head->next->next = ft_create_elem("what's up?");
	t_list *new = ft_create_elem("hello");
	printf("*head =>\n");
	display(head);
	printf("function result =>\n");
	printf("%d\n", ft_list_find(head, new, ft_cmp));
	return 0;
}