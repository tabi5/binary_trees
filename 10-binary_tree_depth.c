#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 *
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, the function returns 0.
 *         Otherwise, it returns the depth of the node.
 *
 * Description: This function measures the depth of
 * a given node in a binary tree.
 *              The depth of a node is defined as the number
 *              of edges from the
 *              node to the root of the tree.
 *              If the node is NULL or the tree is
 *              empty (NULL), the depth is considered to be 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *parent_node;

	if (tree)
	{
		parent_node = tree->parent;
		return (parent_node ? 1 + binary_tree_depth(parent_node) : 0);
	}
	return (0);
}

