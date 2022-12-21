#include "ft_btree.h"

void applyf(void *root)
{
	printf("%s\n", (char*)root);
}

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root->left)
		btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	if (root->right)
		btree_apply_infix(root->right, applyf);
}

int main()
{
	t_btree newrr = {0, 0, "nrr.7"};
	t_btree newrl = {0, 0, "nrl.6"};
	t_btree newlr = {0, 0, "nlr.5"};
	t_btree newll = {0, 0, "nll.4"};
	t_btree newr = {&newrl, &newrr, "nr.3"};
	t_btree newl = {&newll, &newlr, "nl.2"};
	t_btree new = {&newl, &newr, "n.1"};

	btree_apply_infix(&newrl, applyf);
}