#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0.
 *         Otherwise, it returns the height of the tree.
 *
 * Description: This function calculates the height of a binary tree.
 * The height
 *              of a binary tree is defined as the number of edges on
 *              the longest
 *              path from the root node to a leaf node. If the tree is empty
 *              (NULL), the height is considered to be 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;
	size_t left_height = 0, right_height = 0;

	if (tree)
	{
		left_child = tree->left;
		right_child = tree->right;

		left_height = left_child ? 1 + binary_tree_height(left_child) : 0;
		right_height = right_child ? 1 + binary_tree_height(right_child) : 0;

		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

