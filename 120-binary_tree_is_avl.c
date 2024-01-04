#include "binary_trees.h"
#include "limits.h"

/**
 * height - Measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the
 * tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0.
 * Otherwise,
 * it returns the height of the tree.
 */
size_t height(const binary_tree_t *tree);

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid AVL tree, the function returns 1.
 * Otherwise, it returns 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is a valid AVL tree, the function returns 1.
 * Otherwise, it returns 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 *
 * This function recursively calculates the height of a binary tree.
 * The height of a tree is defined as the number of edges on the longest path
 * from the root node to a leaf node. If the tree is empty (NULL),
 * the height is 0.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0.
 * Otherwise, it returns the height of the tree.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l_height = 0, r_height = 0;
		size_t l_increment = 0, r_increment = 0;

		l_increment = tree->left ? 1 : 0;
		r_increment = tree->right ? 1 : 0;

		l_height = l_increment + height(tree->left);
		r_height = r_increment + height(tree->right);

		return ((l_height > r_height) ? l_height : r_height);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 *
 * This function recursively checks if
 * a binary tree is a valid AVL tree.
 * An AVL tree is a binary search tree where the
 * heights of the left and right subtrees
 * differ by at most one, and both the left and
 * right subtrees are also AVL trees.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid AVL tree, the function returns 1.
 * Otherwise, it returns 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt;
	int diff, left_tree_valid, right_tree_valid;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		left_tree_valid = is_avl_helper(tree->left, lo, tree->n - 1);
		right_tree_valid = is_avl_helper(tree->right, tree->n + 1, hi);
		return (left_tree_valid && right_tree_valid);
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 *
 * This function checks if a binary tree is a valid AVL tree.
 * An AVL tree is a binary search tree where
 * the heights of the left and right subtrees
 * differ by at most one, and both the left and
 * right subtrees are also AVL trees.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is a valid AVL tree, the function returns 1.
 * Otherwise, it returns 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_avl;

	if (tree == NULL)
		return (0);
	is_avl = is_avl_helper(tree, INT_MIN, INT_MAX);
	return (is_avl);
}
