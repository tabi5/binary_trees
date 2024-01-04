#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: This function performs an in-order traversal of a binary tree,
 *              starting from the specified root node. It applies the provided
 *              function to each visited node in an in-order sequence.
 *              In-order traversal visits the left subtree first,
 *              then the current
 *              node, and finally the right subtree.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (tree && func)
	{
		left_child = tree->left;
		right_child = tree->right;
		binary_tree_inorder(left_child, func);
		func(tree->n);
		binary_tree_inorder(right_child, func);
	}
}
