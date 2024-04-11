#include "binary_trees.h"

/**
 * array_to_avl - Creates an AVL tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Numb of elements in @array.
 *
 * Return: Pointer to the root node of the created AVL, else NULL.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, p;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (p = 0; p < i; p++)
		{
			if (array[p] == array[i])
				break;
		}
		if (p == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
