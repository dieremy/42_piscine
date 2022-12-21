#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}
/*
#include <stdio.h> 

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
	
	printf("%s\n", ft_list_last(head)->data);
}
*/