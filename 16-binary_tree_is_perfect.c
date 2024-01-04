#include "binary_trees.h"
unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);
/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 *
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, the function returns 1.
 * Otherwise, it returns 0.
 *
 * Description: This function checks if a given node is
 * a leaf in a binary tree.
 *              A leaf node is defined as a node that
 *              has no children (both left
 *              and right pointers are NULL).
 *              The function returns 1 if the node
 *              is a leaf, and 0 otherwise.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	left_child = node->left;
	right_child = node->right;

	return ((left_child == NULL && right_child == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depth of a given node in a binary tree.
 *
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 *
 * Description: This function calculates the depth of
 * a given node in a binary tree.
 *              The depth of a node is defined as the
 *              number of edges from the root
 *              of the tree to the node. The function
 *              recursively traverses the tree
 *              from the given node to its parent
 *              nodes until it reaches the root,
 *              counting the number of edges along the way.
 *              The function returns the
 *              depth of the node.
 */
size_t depth(const binary_tree_t *tree)
{
	binary_tree_t *parent_node;

	parent_node = tree->parent;

	return (parent_node != NULL ? 1 + depth(parent_node) : 0);
}


/**
 * get_leaf - Returns a leaf of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf node.
 *
 * Description: This function finds and returns a leaf
 * node in a binary tree.
 *              Starting from the given root node,
 *              it recursively traverses the
 *              tree until it finds a leaf node
 *              (a node with no children). The
 *              function returns a pointer to
 *              the first encountered leaf node.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (is_leaf(tree) == 1)
		return (tree);

	left_child = tree->left;
	right_child = tree->right;

	return (left_child ? get_leaf(left_child) : get_leaf(right_child));
}


/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 *
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of the current node.
 *
 * Return: If the tree is perfect, the function returns 1.
 * Otherwise, it returns 0.
 *
 * Description: This function checks if a binary tree is perfect,
 * i.e., if every
 *              level of the tree is completely filled
 *              with nodes except possibly
 *              for the last level, which is filled
 *              from left to right. The check
 *              is done recursively by traversing the
 *              tree in a depth-first manner.
 *              The function takes a root node,
 *              the depth of one leaf in the tree,
 *              and the level of the current node as parameters.
 *              It returns 1 if
 *              the tree is perfect and 0 otherwise.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;
	int left_result, right_result;

	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);

	left_child = tree->left;
	right_child = tree->right;

	if (left_child == NULL || right_child == NULL)
		return (0);

	left_result = is_perfect_recursive(left_child, leaf_depth, level + 1);
	right_result = is_perfect_recursive(right_child, leaf_depth, level + 1);

	return (left_result && right_result);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is NULL or not perfect, the function returns 0.
 * Otherwise, it returns 1.
 *
 * Description: This function checks if a binary tree is perfect,
 * i.e., if every
 *              level of the tree is completely filled with
 *              nodes except possibly
 *              for the last level, which is filled
 *              from left to right. The function
 *              calls the `is_perfect_recursive`
 *              function to perform the actual check.
 *              If the tree is NULL or not perfect,
 *              the function returns 0. Otherwise,
 *              it returns 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	const binary_tree_t *leaf_node;
	size_t leaf_depth;

	if (tree == NULL)
		return (0);

	leaf_node = get_leaf(tree);
	leaf_depth = depth(leaf_node);

	return (is_perfect_recursive(tree, leaf_depth, 0));
}

