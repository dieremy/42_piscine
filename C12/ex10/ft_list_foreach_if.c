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

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int(*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

int	ft_cmp(void *d1, void *d2)
{
	return ((int*)d1 - (int*)d2);
}

void func(void *n)
{
	*(char*)n += 10;
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
	t_list *new = ft_create_elem("hello");
	new->next = ft_create_elem("friend");
	t_list *out = ft_create_elem("hello");
	display(new);
	ft_list_foreach_if(new, func, out, ft_cmp);
	display(new);
	display(out);


	return (0);
}