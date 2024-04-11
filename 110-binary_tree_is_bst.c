#include "binary_trees.h"

/**
 * isBEST_help - Compare node in order to verify if a given
 *
 * @tree: the pointer to the root node of the tree to check
 * @mini: low value
 * @maxi: high value
 *
 * Return: 1 if success, else 0
 */
int isBEST_help(const binary_tree_t *tree, int mini, int maxi)
{
	if (tree == NULL)
		return (1);

	if (tree->n < mini || tree->n > maxi)
		return (0);

	return (
		isBEST_help(tree->left, mini, tree->n - 1) &&
		isBEST_help(tree->right, tree->n + 1, maxi)
	);
}

/**
 * binary_tree_is_bst - this checks if a binary tree is a valid Binary Search tree
 *
 * @tree: the pointer to the root node of the tree to check
 * Return: 1 if success, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isBEST_help(tree, INT_MIN, INT_MAX));
}
