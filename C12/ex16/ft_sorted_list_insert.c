#include "ft_list.h"

void	display(t_list *n)
{
	while (n)
	{
		printf("%s\n", n->data);
		n = n->next;
	}
}

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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*list_other_ptr;
	t_list	*temp;
	t_list	*new;

	list_ptr = *begin_list;
	new = ft_create_elem(data);
	new->next = *begin_list;
	*begin_list = new;
	while (list_ptr)
	{
		list_other_ptr = list_ptr->next;
		while (list_other_ptr)
		{
			if ((*cmp)(list_ptr->data, list_other_ptr->data) > 0)
			{
				temp = list_ptr->data;
				list_ptr->data = list_other_ptr->data;
				list_other_ptr->data = temp;
			}
			list_other_ptr = list_other_ptr->next;
		}
		list_ptr = list_ptr->next;
	}
}

int main()
{
	t_list* new = ft_create_elem("2");
	new->next = ft_create_elem("9");
	new->next->next = ft_create_elem("7");
	display(new);
	printf("\n#####S_L_I#####\n\n");
	ft_sorted_list_insert(&new, "3", ft_cmp);
	display(new);
}