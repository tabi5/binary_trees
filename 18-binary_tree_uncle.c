#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: If node is NULL, has no parent, or has no uncle,
 * the function returns NULL.
 *         Otherwise, it returns a pointer to the uncle node.
 *
 * Description: This function finds the uncle of a given node in a binary tree.
 * The uncle
 *              of a node is defined as the sibling of its parent node.
 *              The function takes
 *              a pointer to the node to find the uncle of as a parameter.
 *              If the node is
 *              NULL, has no parent, or has no uncle,
 *              the function returns NULL.
 *              Otherwise,
 *              it returns a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent_node;
	binary_tree_t *grandparent_node;
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (node == NULL)
		return (NULL);

	parent_node = node->parent;
	if (parent_node == NULL)
		return (NULL);

	grandparent_node = parent_node->parent;
	if (grandparent_node == NULL)
		return (NULL);

	left_child = grandparent_node->left;
	right_child = grandparent_node->right;

	if (left_child == parent_node)
		return (right_child);
	return (left_child);
}
