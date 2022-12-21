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
	int	i;

	i = 1;
	while (n && i)
	{
		printf("%s\n", n->data);
		n = n->next;
		i++;
	}
}

int	ft_cmp(void *d1, void *d2)
{
	return ((int*)d1 - (int*)d2);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list_ptr;
	t_list	*list_other_ptr;
	t_list	*temp;

	list_ptr = *begin_list;
	while (list_ptr)
	{
		list_other_ptr = *begin_list;
		while (list_other_ptr->next)
		{
			if ((*cmp)(list_other_ptr->data, list_other_ptr->next->data) > 0)
			{
				temp = list_other_ptr->data;
				list_other_ptr->data = list_other_ptr->next->data;
				list_other_ptr->next->data = temp;

			}
			list_other_ptr = list_other_ptr->next;
		}
		list_ptr = list_ptr->next;
	}
}

void	ft_list_sort2(t_list **begin_list, int (*cmp)())
{
	t_list	*list1;
	t_list	*list2;
	t_list	*temp;

	list1 = *begin_list;
	while (list1)
	{
		list2 = list1->next;
		while (list2)
		{
			if ((*cmp)(list1->data, list2->data) > 0)
			{
				temp = list1->data;
				list1->data = list2->data;
				list2->data = temp;
			}
			list2 = list2->next;
		}
		list1 = list1->next;
	}
}

int main()
{
	t_list *new = ft_create_elem("d");
	new->next = ft_create_elem("c");
	new->next->next = ft_create_elem("a");
	new->next->next->next = ft_create_elem("b");
	display(new);
	printf("\n######SORT_LIST######\n\n");
	ft_list_sort2(&new, ft_cmp);
	display(new);
}