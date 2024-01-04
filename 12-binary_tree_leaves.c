#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to count the leaves of.
 *
 * Return: The number of leaves in the tree.
 *
 * Description: This function counts the number of leaves in a binary tree.
 *              A leaf node is a node that has no children (both left and right
 *              pointers are NULL). If the tree is empty (NULL), the function
 *              returns 0.
 *              The number of leaves in a binary tree is the sum of the number
 *              of leaves in its left subtree, right subtree, and the root node
 *              itself (if it is a leaf).
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;
	size_t left_leaves = 0, right_leaves = 0;

	if (tree)
	{
		left_child = tree->left;
		right_child = tree->right;

		left_leaves = left_child ? binary_tree_leaves(left_child) : 0;
		right_leaves = right_child ? binary_tree_leaves(right_child) : 0;

		return (((!left_child && !right_child) ? 1 : 0) +
				left_leaves + right_leaves);
	}
	return (0);
}

