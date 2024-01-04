#include "binary_trees.h"
/**
 * array_to_bst - Builds a binary search tree from an array.
 *
 * @array: A pointer to the first element
 * of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST,
 * or NULL on failure.
 *
 * Description: Builds a binary search tree (BST)
 * from an array. Takes a pointer
 * to the first element of the array to be converted (`array`)
 * and the number of
 * elements in the array (`size`). If the `array`
 * pointer is NULL, the function
 * returns NULL. The function iterates over
 * the elements in the array and checks
 * for duplicates. For each unique element,
 * it calls the `bst_insert` function
 * to insert the element into the BST.
 * If the insertion fails, the function
 * returns NULL. Finally, it returns
 * a pointer to the root node of the created BST.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;
	int inserted;

	if (array == NULL)
		return (NULL);

	i = 0;
	do {
		j = 0;
		inserted = 1;
		do {
			if (array[j] == array[i])
			{
				inserted = 0;
				break;
			}
			j++;
		} while (j < i);

		if (inserted)
		{
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
		i++;
	} while (i < size);

	return (tree);
}
