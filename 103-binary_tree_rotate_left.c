#include "binary_trees.h"
/**
 * binary_tree_rotate_left - Performs
 *a left rotation on a binary tree.
 * @tree: A pointer to the root node
 *of the tree to rotate.
 *
 * Return: A pointer to the new root
 *node after rotation.
 *
 * Description: This function performs
 *a left rotation on a binary tree.
 * It takes a pointer to the root node of
 *the tree to rotate as a parameter.
 * If the `tree` pointer is `NULL` or if
 *the `right` child of the tree is `NULL`,
 * the function returns `NULL`
 *indicating an invalid rotation.
 * Otherwise, it performs the left rotation
 *and returns a pointer to the new root node
 * after the rotation.
 *
 * The left rotation is performed by:
 * - Setting the `pivot` node as the `right`
 *child of the `tree` node.
 * - Updating the `left` child of the `pivot`
 *node to be the original `tree` node.
 * - Updating the `right` child of the `tree`
 *node to be the left child of the `pivot` node.
 * - Updating the parent pointers accordingly.
 * - Finally, updating the parent of the original
 *parent of the `tree` node to point to the `pivot` node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot_node, *temp, *parent_node;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot_node = tree->right;
	temp = pivot_node->left;
	parent_node = tree->parent;

	pivot_node->left = tree;
	tree->right = temp;

	if (temp != NULL)
		temp->parent = tree;

	tree->parent = pivot_node;
	pivot_node->parent = parent_node;

	if (parent_node != NULL)
	{
		if (parent_node->left == tree)
			parent_node->left = pivot_node;
		else
			parent_node->right = pivot_node;
	}

	return (pivot_node);
}

