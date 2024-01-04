#include "binary_trees.h"
/**
 * bst_search - Searches for a value in a binary search tree.
 *
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 *
 * Return: If tree is NULL or value not found, NULL.
 * Otherwise, a pointer to
 *         the node containing the value.
 *
 * Description: Searches for a value in a binary search tree (BST).
 * Takes a
 * pointer to the root node of the BST to search (`tree`)
 * and the value to
 * search for in the BST (`value`).
 * If the `tree` pointer is NULL or the value
 * is not found in the BST, the function returns NULL.
 * Otherwise, it recursively
 * searches for the value by comparing it
 * with the value in the current node.
 * If the value is found, a pointer to the
 * node containing the value is returned.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *curr;
	int found;

	if (tree != NULL)
	{
		curr = tree;
		found = 0;
		do {
			if (curr->n == value)
			{
				found = 1;
				break;
			}
			else if (curr->n > value)
				curr = curr->left;
			else
				curr = curr->right;
		} while (curr != NULL);

		if (found)
			return ((bst_t *)curr);
	}
	return (NULL);
}
