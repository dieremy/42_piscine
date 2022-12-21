#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = (t_btree*)malloc(sizeof(t_btree));
	if (new)
	{
		new->item = item;
		new->right = 0;
		new->left = 0;
	}
	return (new);
}

int main()
{
	t_btree *out = btree_create_node("13");
	printf("%s\n", out->item);
	printf("%d\n", out->right);
	printf("%d\n", out->left);
}