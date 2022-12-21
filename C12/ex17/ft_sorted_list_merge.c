#include "ft_list.h"

void	display(t_list *d)
{
	while (d)
	{
		printf("%s\n", d->data);
		d = d->next;
	}
}

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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*temp;
	t_list	*list_ptr;
	t_list	*list_other_ptr;

	list_ptr = *begin_list1;
	while (list_ptr->next)
		list_ptr = list_ptr->next;
	list_ptr->next = begin_list2;
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
	t_list* new = ft_create_elem("hello");
	new->next = ft_create_elem("friend");
	t_list* out  = ft_create_elem("have a ");
	out->next = ft_create_elem("nice day");
	printf("\n\n<= new =>\n");
	display(new);
	printf("\n\n<= out =>\n");
	display(out);
	ft_sorted_list_merge(&new, out, ft_cmp);
	printf("\n\n<= merged =>\n");
	display(new);
}