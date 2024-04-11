#include "binary_trees.h"

/**
 * count_nodes - function that counts inside a tree
 * @root:  the node
 *
 * Return: the number odes
 */

int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}


/**
 * is_complete - Checks if a tree is complete
 * @root: A pointer to tree's root
 * @indes: the index of the node been evaluated
 * @n: the number of trees nod
 *
 * Return: 1 if the tree is a heap, else 0
 */

int is_complete(binary_tree_t *root, int indes, int n)
{
	if (!root)
		return (0);

	if (index >= n)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if (root->left && !root->right)
		return (is_complete(root->left, indes * 2 + 1, n));

	return (is_complete(root->left, indes * 2 + 1, n) &&
		is_complete(root->right, indes * 2 + 2, n));
}

/**
 * binary_tree_is_complete - Checks for bt complete
 * @tree: the Pointer to root
 *
 * Return: 1 if
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nod;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	nod = count_nodes(root);

	return (is_complete(root, 0, nod));
}
