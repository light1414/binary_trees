#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree
 *
 * @array: the pointer to the first element of the array to be changed
 * @size: the numb of element in the array
 * Return: pointer to the root node of the created BST, else NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t lent;
	bst_t *tree = NULL;

	for (lent = 0; lent < size; lent++)
		bst_insert(&tree, array[lent]);

	return (tree);
}
