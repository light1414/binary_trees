#include "binary_trees.h"

binary_tree_t *sibling(binary_tree_t *node);

/**
 * binary_tree_uncle - it finds the uncle of a node in a binary tree
 * @node: the node to find uncle for
 *
 * Return: a pointer to uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	return (sibling(node->parent));
}

/**
 * sibling - measures the sibling node to find uncle
 * @node: to find sibling from
 * Return: the sibling of node
 */
binary_tree_t *sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
