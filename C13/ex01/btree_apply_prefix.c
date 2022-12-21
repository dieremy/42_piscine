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

void	applyf(void *root)
{
	printf("%s\n", (char*)root);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	(*applyf)(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

int main()
{
	t_btree *out = btree_create_node("hello");
	out->right = "my";
	out->left = "friend";
	printf("node = %s\n", out->item);
	printf("R = %s\n", out->right);
	printf("L = %s\n", out->left);
	btree_apply_prefix(out->left, &applyf);
	//printf("node = %s\n", out->item);
	//printf("R = %s\n", out->right);
	//printf("L = %s\n", out->left);
}