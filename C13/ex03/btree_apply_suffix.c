#include "ft_btree.h"

void	applyf(void *root)
{
	printf("%s\n", (char*)root);
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
	t_btree outrr = {0, 0, "orr.7"};
	t_btree	outrl = {0, 0, "orl.6"};
	t_btree outlr = {0, 0, "olr.5"};
	t_btree	outll = {0, 0, "oll.4"};
	t_btree	outr = {&outrl, &outrr, "or.3"};
	t_btree	outl = {&outll, &outlr, "ol.2"};
	t_btree out = {&outl, &outr, "o.1"};

	btree_apply_suffix(&out, applyf);
}