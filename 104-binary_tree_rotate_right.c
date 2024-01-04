#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 *
 * Description: Performs a right rotation on a binary tree by taking a pointer
 *              to the root node of the tree to rotate. If the `tree` pointer
 *              is `NULL` or if the `left` child of the tree is `NULL`, the
 *              function returns `NULL` to indicate an invalid rotation.
 *              Otherwise, it performs the right rotation and returns a pointer
 *              to the new root node after the rotation.
 *
 *              The right rotation is performed by:
 *              - Setting the `pivot` node as the `left` child of the `tree`
 *                node.
 *              - Updating the `right` child of the `pivot` node to be the
 *                original `tree` node.
 *              - Updating the `left` child of the `tree` node to be the right
 *                child of the `pivot` node.
 *              - Updating the parent pointers accordingly.
 *              - Finally, updating the parent of the original parent of the
 *                `tree` node to point to the `pivot` node.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tmp, *parent_node;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tmp = pivot->right;
	parent_node = tree->parent;

	pivot->right = tree;
	tree->left = tmp;

	if (tmp != NULL)
		tmp->parent = tree;

	tree->parent = pivot;
	pivot->parent = parent_node;

	if (parent_node != NULL)
	{
		if (parent_node->left == tree)
			parent_node->left = pivot;
		else
			parent_node->right = pivot;
	}

	return (pivot);
}

