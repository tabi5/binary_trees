#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 *
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If successful, a pointer to the newly created node.
 *         Otherwise, NULL.
 *
 * Description: This function creates a new binary tree node
 * with the given value
 *              and sets its parent, left, and right pointers to NULL.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	size_t node_size;

	/* Get the size of the new node */
	node_size = sizeof(binary_tree_t);

	/* Dynamically allocate memory for the new node */
	new_node = malloc(node_size);
	if (new_node == NULL)
		return (NULL);

	/* Initialize the attributes of the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
