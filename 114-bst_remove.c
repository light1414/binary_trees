#include "binary_trees.h"
/**
 * min_finder - It search the mini root
 * @root: the pointer to the tree
 * Return: min numb
 */

bst_t *min_finder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - this removes a node from a Binary Search Tree
 *
 * @root: the pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temm, *parents;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temm = root;
			parents = root->parents;
			root = root->right;
			root->parents = parents;
			free(temm);
		}
		else if (root->right == NULL)
		{
			temm = root;
			parents = root->parents;
			root = root->left;
			root->parents = parents;
			free(temm);
		}
		else
		{
			temm = min_finder(root->right);
			root->n = temm->n;
			root->right = bst_remove(root->right, temm->n);
		}
	}
	return (root);
}
