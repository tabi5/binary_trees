#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the binary tree.
 *
 * Description: This function calculates the size of a binary tree, which is
 *              defined as the total number of nodes in the tree. If the tree
 *              is empty (NULL), the size is considered to be 0.
 *              The size of a binary tree is the sum of the sizes of its left
 *              subtree, right subtree, and the root node itself.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;
	size_t left_size = 0, right_size = 0;

	if (tree)
	{
		left_child = tree->left;
		right_child = tree->right;

		left_size = left_child ? binary_tree_size(left_child) : 0;
		right_size = right_child ? binary_tree_size(right_child) : 0;

		return (1 + left_size + right_size);
	}
	return (0);
}

