#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf of a binary tree.
 *
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, returns 1.
 *         Otherwise, returns 0.
 *
 * Description: This function determines whethera given node in a binary tree
 *              is a leaf node. A leaf node is defined as a node that has no
 *              children (neither left child nor right child).
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (node == NULL)
		return (0);

	left_child = node->left;
	right_child = node->right;

	if (left_child != NULL || right_child != NULL)
		return (0);

	return (1);
}

