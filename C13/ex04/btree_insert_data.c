#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = (t_btree*)malloc(sizeof(t_btree));
	new->item = item;
	new->right = 0;
	new->left = 0;
	return (new);
}

int	cmpf(void *i1, void *i2)
{
	return ((char*)i1 - (char*)i2);
}

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (*root == NULL)
		*root = btree_create_node(item);
	node = *root;
	if ((*cmpf)(item, (*root)->item) < 0)
	{
		if (node->left)
			btree_insert_data(&node->left, item, cmpf);
		else
			node->left = btree_create_node(item);
	}
	else
	{
		if (node->right)
			btree_insert_data(&node->right, item, cmpf);
		else
			node->right = btree_create_node(item);
	}
}

void	applyf(void *n)
{
	printf("%s\n", (char *)n);
}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_suffix(root->left, applyf);
	if (root->right)
		btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}

int main()
{
	t_btree newrr = {0, 0, "newrr.18"};
	t_btree newrl = {0, 0, "newrl.20"};
	t_btree newlr = {0, 0, "newlr.2"};
	t_btree newll = {0, 0, "newll.6"};
	t_btree newr = {&newrl, &newrr, "newr.3"};
	t_btree newl = {&newll, &newlr, "newl.4"};
	t_btree new = {&newl, &newr, "new.5"};
	t_btree *root = &new;
	btree_apply_suffix(&new, applyf);
	printf("\n################\n");
	btree_insert_data(&root, "1", &cmpf);
	btree_apply_suffix(&new, applyf);

}