#include "ft_list.h"

t_list	*ft_create_elem(void *d)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		new->data = d;
		new->next = NULL;
	}
	return (new);
}

void	display(t_list *d)
{
	while (d)
	{
		printf("%s\n", d->data);
		d = d->next;
	}
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*temp;

	list1 = begin_list;
	while (list1)
	{
		list2 = list1->next;
		while (list2)
		{
			temp = list1->data;
			list1->data = list2->data;
			list2->data = temp;
			list2 = list2->next;
		}
		list1 = list1->next;
	}
}

int main()
{
	t_list* new = ft_create_elem("hello");
	new->next = ft_create_elem("world");
	display(new);
	printf("\n#####REVERSE_FUN#####\n\n");
	ft_list_reverse_fun(new);
	display(new);
}