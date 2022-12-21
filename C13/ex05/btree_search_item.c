#include "ft_btree.h"

int	cmpf(void *i1, void *i2)
{
	return ((char*)i1 - (char*)i2);
}

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*out;

	if (root)
	{
		out = btree_search_item(root->left, data_ref, cmpf);
		if (out)
			return (out);
		if (cmpf(root->item, data_ref) == 0)
			return (root->item);
		out = btree_search_item(root->right, data_ref, cmpf);
		if (out)
			return (out);
	}
	return (0);
}

t_btree	*btree_create_node(void *item)
{
	t_btree	*new = (t_btree*)malloc(sizeof(t_btree));
	new->item = item;
	new->right = 0;
	new->left = 0; 
	return (new);
}

int main()
{//
	t_btree newrr = {0, 0, "1"};
	t_btree newrl = {0, 0, "9"};
	t_btree newlr = {0, 0, "4"};
	t_btree newll = {0, 0, "5"};
	t_btree newr = {&newrl, &newrr, "6"};
	t_btree newl = {&newll, &newlr, "3"};
	t_btree new = {&newl, &newr, "2"};
/*
	t_btree *new = btree_create_node("1");
	new->left = btree_create_node("8");
	new->right = btree_create_node("5");*/
	char *out = btree_search_item(&new, "4", cmpf);
	printf("%s\n", out);
}