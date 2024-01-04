#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary tree is full recursively.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is not full, the function returns 0.
 *         Otherwise, it returns 1.
 *
 * Description: This function checks if a binary tree is full, i.e., if every
 *              node in the tree has either 0 or 2 children. The check is done
 *              recursively by traversing the tree in a depth-first manner.
 *              If the tree is empty (NULL), it is considered to be full.
 */
int is_full_recursive(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (tree != NULL)
	{
		left_child = tree->left;
		right_child = tree->right;

		if ((left_child != NULL && right_child == NULL) ||
				(left_child == NULL && right_child != NULL) ||
				is_full_recursive(left_child) == 0 ||
				is_full_recursive(right_child) == 0)
			return (0);
	}
	return (1);
}


/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not full, the function returns 0.
 *         Otherwise, it returns 1.
 *
 * Description: This function checks if a binary tree is full, i.e., if every
 *              node in the tree has either 0 or 2 children. It calls the
 *              `is_full_recursive` function to perform the actual check. If
 *              the tree is empty (NULL), it is considered to be not full.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full;

	if (tree == NULL)
		return (0);

	is_full = is_full_recursive(tree);
	return (is_full);
}
