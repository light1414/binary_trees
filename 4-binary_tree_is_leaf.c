#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Function that checks if the node is a leaf
 * @node: The nodes is binary trees
 * Return: 1 if node is a leaf, else 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}
