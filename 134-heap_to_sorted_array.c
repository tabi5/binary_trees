#include "binary_trees.h"

/**
 * tree_size - Measures the sum of heights of a binary tree.
 *
 * This function takes a pointer to the root node
 * of a binary tree and calculates the
 * sum of heights of the tree. The sum of heights
 * is defined as the sum of the heights
 * of all the individual nodes in the tree.
 * The function recursively calculates the
 * sum of heights by traversing the left and
 * right subtrees and adding 1 for each level
 * visited. The sum of heights of an empty tree is 0.
 *
 * @tree: Pointer to the root node of the
 * tree to measure the sum of heights.
 *
 * Return: The sum of heights of the
 * tree or 0 if the tree is NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t left_tree_size = 0;
	size_t right_tree_size = 0;
	size_t total_size;

	if (!tree)
		return (0);

	if (tree->left)
		left_tree_size = 1 + tree_size(tree->left);

	if (tree->right)
		right_tree_size = 1 + tree_size(tree->right);

	total_size = left_tree_size + right_tree_size;
	return (total_size);
}


/**
 * heap_to_sorted_array - Converts a Binary Max
 * Heap to a sorted array of integers.
 *
 * This function takes a pointer to the root node of
 * a Binary Max Heap and converts it
 * to a sorted array of integers in descending order.
 * The function uses the heap_extract
 * function to extract the elements from the heap one by one,
 * resulting in a sorted array.
 * It calculates the size of the array by calling the tree_size function.
 * The function
 * dynamically allocates memory for the array and returns
 * a pointer to the sorted array.
 *
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 * Return: Pointer to the array sorted in descending order.
 *         NULL if the heap is NULL or if memory allocation fails.
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i;
	int *array = NULL;
	size_t heap_size;
	int extracted_value;

	if (!heap || !size)
		return (NULL);

	heap_size = tree_size(heap) + 1;
	*size = heap_size;

	array = malloc(sizeof(int) * heap_size);

	if (!array)
		return (NULL);

	for (i = 0; heap; i++)
	{
		extracted_value = heap_extract(&heap);
		array[i] = extracted_value;
	}

	return (array);
}
