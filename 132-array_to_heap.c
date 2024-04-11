#include "binary_trees.h"

/**
 * array_to_heap - cteats a Max Binary Heap tree from an array.
 *
 * @array: pointer to the first element of the array to be converted.
 * @size: Number of element in the array.
 *
 * Return: A pointer to the root node of the created one, else NULL.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int n;
	heap_t *root = NULL;

	for (n = 0; n < size; n++)
		heap_insert(&root, array[nx]);

	return (root);
}
