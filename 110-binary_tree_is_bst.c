#include "binary_trees.h"
#include "limits.h"
/**
 * is_bst_helper - Recursively checks if a binary tree is
 * a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid binary search tree, returns 1.
 * Otherwise, returns 0.
 *
 * Description: This function is a helper function that
 * recursively checks if a binary tree
 * is a valid binary search tree (BST). It takes
 * a pointer to the root node of the tree to check,
 * along with the current lower and upper bounds of
 * the valid node values.
 * If the tree is not a valid BST, the function returns 0.
 * Otherwise, it continues the recursive
 * checks on the left and right subtrees,
 * updating the bounds accordingly.
 *
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	int isBST = 1;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			isBST = 0;

		if (isBST)
			isBST = is_bst_helper(tree->left, lo, tree->n - 1) &&
				is_bst_helper(tree->right, tree->n + 1, hi);
	}

	return isBST;
}

/**
 * binary_tree_is_bst - Checks if a binary
 * tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is a valid binary
 * search tree, returns 1. Otherwise, returns 0.
 *
 * Description: This function checks if
 * a binary tree is a valid binary search tree (BST).
 * It takes a pointer to the root node of the tree to check.
 * If the tree is NULL, the function
 * returns 0 as an empty tree is not considered a valid BST.
 * Otherwise, it calls the `is_bst_helper`
 * function with the initial lower bound as `INT_MIN` and
 * the initial upper bound as `INT_MAX`.
 * The `is_bst_helper` function performs the
 * recursive checks to validate the BST property.
 * If the tree is a valid BST, the function returns 1.
 * Otherwise, it returns 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int isBST = 0;

	if (tree != NULL)
		isBST = is_bst_helper(tree, INT_MIN, INT_MAX);

	return isBST;
}

