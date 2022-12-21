#include "ft_list.h"

t_list	*ft_create_elem(void* data)
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

void	ft_free(void *n)
{
	n = NULL;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*prev;

	list_ptr = *begin_list;
	if (list_ptr && (*cmp)(list_ptr->data, data_ref) == 0)
	{
		*begin_list = list_ptr->next;
		(*free_fct)(list_ptr->data);
		free(list_ptr);
		list_ptr = *begin_list;
		prev = *begin_list;
	}
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			prev->next = list_ptr->next;
			(*free_fct)(list_ptr->data);
			free(list_ptr);
			list_ptr = prev;
		}
		prev = list_ptr;
		list_ptr = list_ptr->next;
	}
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
	t_list *new;
	
	new = ft_create_elem("hello");
	new->next = ft_create_elem("friend");
	display(new);
	char *out = malloc(sizeof(char) * 5);
	out = "hello";
	ft_list_remove_if(&new, out, ft_cmp, ft_free);
	display(new);
}