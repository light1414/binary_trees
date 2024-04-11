#include "binary_trees.h"

/**
 * binary_tree_inorder - applies post-order traversal to a binary tree.
 * @tree: const pointer to root node to start traversal at
 * @func: A function to call on tree node's data
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
