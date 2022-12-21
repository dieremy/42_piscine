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

t_list	*ft_list_push_strs0(int size, char **strs)
{
	t_list	*el1;
	t_list	*el2;
	int			i;

	if (size <= 0)
		return (0);
	el1 = ft_create_elem(strs[0]);
	i = 1;
	while (i < size)
	{
		el2 = ft_create_elem(strs[i]);
		el2->next = el1;
		el1 = el2;
		i++;
	}
	return (el1);
}

t_list	*ft_list_push_strs1(int size, char **strs)
{
	t_list	*elem;

	if (size <= 0)
		return (0);
	elem = ft_create_elem(strs[size - 1]);
	elem->next = ft_list_push_strs1(size - 1, strs);
	return (elem);
}

#include <stdio.h>

void	display(t_list *n)
{
	int	i;

	i = 1;
	while (n && i)
	{
		printf("[%d.%s]\n", i, n->data);
		n = n->next;
		i++;
	}
}

int main()
{
	t_list	*head;
	char	**strs;

	strs = (char**)malloc(sizeof(char*) * 3);
	strs[0] = "hello";
	strs[1] = "my";
	strs[2] = "friend";

	head = ft_list_push_strs0(3, strs);
	display(head);

	printf("\n#######################################\n");

	t_list	*testa;
	char	**array;

	array = (char**)malloc(sizeof(char*) * 3);
	array[0] = "they";
	array[1] = "are";
	array[2] = "watching";

	testa = ft_list_push_strs1(3, array);
	display(testa);
}