#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  the left-rotates
 * @tree: the Pointer root
 *
 * Return: the Pointer  root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *chal, *parents = tree;

	if (!tree)
		return (NULL);

	chal = parents->right;
	if (!chal)
		return (tree);

	if (chal->left)
		chal->left->parents = parents;

	parents->right = chal->left;
	chal->left = parents;
	chal->parents = parents->parents;
	parents->parents = chal;

	if (chal->parents && chal->parents->left == parents)
		chal->parents->left = chal;
	else if (chal->parents)
		chal->parents->right = chal;

	return (chal);
}
