#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of
 * a node in a binary tree.
 *
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling,
 * the function returns NULL.
 *         Otherwise, it returns a pointer to the sibling.
 *
 * Description: This function finds the sibling of
 * a given node in a binary tree.
 *              The sibling of a node is defined as
 *              another node that shares the
 *              same parent. The function takes
 *              a pointer to the node to find the
 *              sibling of as a parameter.
 *              If the node is NULL or there is no sibling,
 *              the function returns NULL. Otherwise,
 *              it returns a pointer to the sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent_node;
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (node == NULL)
		return (NULL);

	parent_node = node->parent;
	if (parent_node == NULL)
		return (NULL);

	left_child = parent_node->left;
	right_child = parent_node->right;

	if (left_child == node)
		return (right_child);
	return (left_child);
}

