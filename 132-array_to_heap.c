#include "binary_trees.h"
/**
 * array_to_heap - Builds a Max Binary Heap
 * tree from an array.
 *
 * This function takes an array of integers
 * and the size of the array and builds a
 * Max Binary Heap tree from it. It iterates through
 * the array and calls the
 * heap_insert function to insert each element into
 * the Max Binary Heap. The heap_insert
 * function ensures that the heap property is
 * maintained after each insertion.
 *
 * @array: A pointer to the first element of
 * the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the
 * created Max Binary Heap.
 *         NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;
	heap_t *new_root;

	for (i = 0; i < size; i++)
	{
		new_root = heap_insert(&root, array[i]);
		root = new_root;
	}

	return (root);
}
