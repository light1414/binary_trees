#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
const binary_tree_t *get_leaf(const binary_tree_t *tree);
unsigned char is_leaf(const binary_tree_t *node);
size_t leaf_depth, size_t level);

/**
 * binary_tree_is_perfect - it checks if a binary tree is perfect.
 *
 * @tee: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tee)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}

/**
 * depth - it returns the depth of a given
 *         node in a binary tree.
 * @tree: Pointer to the node to gets the depth of.
 *
 * Return: depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - it returns a leaf of a binary tree.
 * @tree: Pointer to the root node of the tree to find a leaf in.
 *
 * Return: Pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive -  Checks if a binary tree is perfect recursively.
 * @tree: Pointer to the root node of the tree to check.
 * @leaf_depth: depth of one leaf in the binary tree.
 * @level: the level of current node.
 *
 * Return: If the tree is perfect, 1, else 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: Pointer to the node to check.
 *
 * Return: If the node is a leaf, 1, else, 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
