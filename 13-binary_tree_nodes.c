#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function returns 0.
 *         Otherwise, it returns the number of nodes with at least 1 child.
 *
 * Description: This function counts the number of nodes
 * with at least 1 child in a binary tree.
 *              A node with at least 1 child is any node that
 *              has either a left child or a right child
 *              or both. If the tree is empty (NULL),
 *              the function returns 0.
 *              The number of nodes with at least 1 child in
 *              a binary tree is the sum of the number
 *              of nodes with at least 1 child in its left subtree,
 *              right subtree, and the root node
 *              itself (if it has at least 1 child).
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;
	size_t left_nodes = 0, right_nodes = 0;

	if (tree)
	{
		left_child = tree->left;
		right_child = tree->right;

		left_nodes = left_child ? binary_tree_nodes(left_child) : 0;
		right_nodes = right_child ? binary_tree_nodes(right_child) : 0;

		return (((left_child || right_child) ? 1 : 0) +
				left_nodes + right_nodes);
	}
	return (0);
}
