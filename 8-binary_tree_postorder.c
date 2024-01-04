#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: This function performs a post-order traversal of a binary tree,
 *              starting from the specified root node. It applies the provided
 *              function to each visited node in a post-order sequence.
 *              Post-order traversal visits the left subtree first,
 *              then the right
 *              subtree, and finally the current node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (tree && func)
	{
		left_child = tree->left;
		right_child = tree->right;
		binary_tree_postorder(left_child, func);
		binary_tree_postorder(right_child, func);
		func(tree->n);
	}
}

