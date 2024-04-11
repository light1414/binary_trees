#include "binary_trees.h"

/**
 * bst_insert - functon that inserts a value in a Binary Search Tree
 *
 * @tree: the double pointer to the root node of the BST to insert the value
 * @value: value of store in the node to be inserted
 * Return: the pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tree_3;

	if (tree == NULL || *tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	tree_3 = *tree;

	while (tree_3 != NULL)
	{
		if (tree_3->n == value)
			return (NULL);
		if (tree_3->n > value)
		{
			if (tree_3->left == NULL)
			{
				tree_3->left = binary_tree_node(tree_3, value);
				return (tree_3->left);
			}
			tree_3 = tree_3->left;
		}
		if (tree_3->n < value)
		{
			if (tree_3->right == NULL)
			{
				tree_3->right = binary_tree_node(tree_3, value);
				return (tree_3->right);
			}
			tree_3 = tree_3->right;
		}
	}
	return (NULL);
}
