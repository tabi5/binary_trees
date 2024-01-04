#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right-child
 *                            of another in a binary tree.
 *
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: If successful, a pointer to the newly inserted node.
 *         If parent is NULL or an error occurs, returns NULL.
 *
 * Description: This function inserts a new node with the given value
 *              as the right-child of the specified parent
 *              node in a binary tree.
 *              If the parent already has a right-child,
 *              the new node takes its place
 *              and the old right-child is set as the
 *              right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	right_child = parent->right;
	if (right_child != NULL)
	{
		new_node->right = right_child;
		right_child->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
