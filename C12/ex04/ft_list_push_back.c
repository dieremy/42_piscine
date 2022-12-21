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

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*out;

	out = *begin_list;
	if (out)
	{
		while (out->next)
			out = out->next;
		out->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);

}

/*#include <stdio.h>
void	display(t_list *n)
{
	int	i;

	i = 1;
	while (n && i)
	{
		printf("[%d.%s] ", i, n->data);
		n = n->next;
		i++;
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

	ft_list_push_back(&head, "how you doing?");
	display(head);
}*/
