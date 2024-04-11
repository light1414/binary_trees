#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that counts leaves in a binary tree
 * @tree: A pointer node binary tree
 * Return: The Numb of leaves in a binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		nodes += 1;
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);
	return (nodes);
}
