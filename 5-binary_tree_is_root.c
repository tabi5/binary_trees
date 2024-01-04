#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is a root of a binary tree.
 *
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a root, returns 1.
 *         Otherwise, returns 0.
 *
 * Description: This function determines whether a given node in a binary tree
 *              is the root node. A root node is defined as a node that has no
 *              parent (i.e., its parent pointer is NULL).
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	binary_tree_t *parent_node;

	if (node == NULL)
		return (0);

	parent_node = node->parent;

	if (parent_node != NULL)
		return (0);

	return (1);
}
