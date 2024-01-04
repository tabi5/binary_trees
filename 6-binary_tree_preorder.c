#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: This function performs a pre-order traversal of a binary tree,
 *              starting from the specified root node. It applies the provided
 *              function to each visited node in a pre-order sequence.
 *              Pre-order traversal visits the current node first,
 *              then its left
 *              subtree, and finally its right subtree.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (tree && func)
	{
		func(tree->n);
		left_child = tree->left;
		right_child = tree->right;
		binary_tree_preorder(left_child, func);
		binary_tree_preorder(right_child, func);
	}
}

