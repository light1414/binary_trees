#include "binary_trees.h"

int binary_tree_is_avl(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);

/**
 * binary_tree_is_avl - this checks if a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and else 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - function that checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * @lo: value of the smallest node visited thus far.
 * @hi: Value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, else 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * height - this gets the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, otherwise return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
