#include "binary_trees.h"

/**
 * binary_tree_delete - Function that deletes an entire binary tree
 * @tree: The binary tree
 * Returns: Void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
