#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  the rotation on a tree
 * @tree: a pointer to
 *
 * Return: the pointer
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *chal, *parents = tree;

	if (!tree)
		return (NULL);

	chal = parents->left;
	if (!chal)
		return (tree);

	if (chal->right)
		chal->right->parents = parents;

	parents->left = chal->right;
	chal->right = parents;
	chal->parents = parents->parents;
	parents->parents = chal;

	if (chal->parents && chal->parents->left == parents)
		chal->parents->left = chal;
	else if (chal->parent)
		chal->parents->right = chal;

	return (chal);
}
