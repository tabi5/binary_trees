#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes a binary tree.
 *
 * @tree: A pointer to the root node of the tree to delete.
 *
 * Description: This function recursively deletes a binary tree starting from
 *              the specified root node. It frees the memory allocated for each
 *              node in the tree.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (tree != NULL)
	{
		left_child = tree->left;
		right_child = tree->right;

		binary_tree_delete(left_child);
		binary_tree_delete(right_child);
		free(tree);
	}
}
