#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, the function returns 0.
 *         Otherwise, it returns the balance factor.
 *
 * Description: This function measures the balance factor of a binary tree.
 *              The balance factor of a node is calculated as the difference
 *              between the heights of its left and right subtrees. If the tree
 *              is empty (NULL), the balance factor is considered to be 0.
 *              The balance factor can be used to determine
 *              whether a binary tree
 *              is balanced or not. A balanced tree has
 *              a balance factor of -1, 0,
 *              or 1, while an unbalanced tree has
 *              a balance factor less than -1
 *              or greater than 1.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;
	int left_height = 0, right_height = 0;

	if (tree)
	{
		left_child = tree->left;
		right_child = tree->right;

		left_height = left_child ? binary_tree_height(left_child) : 0;
		right_height = right_child ? binary_tree_height(right_child) : 0;

		return (left_height - right_height);
	}
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0.
 *         Otherwise, it returns the height of the tree.
 *
 * Description: This function measures the height of a binary tree.
 *              The height of a tree is defined as the number of edges
 *              in the longest path from the root node to a leaf node.
 *              If the tree is empty (NULL), the height is considered to be 0.
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

		left_height = left_child ? 1 + binary_tree_height(left_child) : 1;
		right_height = right_child ? 1 + binary_tree_height(right_child) : 1;

		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

