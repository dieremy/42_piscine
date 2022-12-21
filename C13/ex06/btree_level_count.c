#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new = (t_btree*)malloc(sizeof(t_btree));
	new->item = item;
	new->left = 0;
	new->right = 0;
	return (new);
}

int	btree_level_count(t_btree *root)
{
	int	countl;
	int	countr;
	int max;

	if (root)
	{	
		countl = btree_level_count(root->left);
		countr = btree_level_count(root->right);
		max = countl;
		if (max < countr)
			max = countr;
		return (max + 1);
	}
	return (0);
}

int main()
{
	t_btree *new = btree_create_node("2");
	new->left = btree_create_node("3");
	new->right = btree_create_node("4");
	/*new->left->left = btree_create_node("5");
	new->left->right = btree_create_node("6");
	new->left->left->left = btree_create_node("7");
	new->left->left->right = btree_create_node("8");
	new->left->left->left->left = btree_create_node("9");*/
	printf("%d\n", btree_level_count(new));


}