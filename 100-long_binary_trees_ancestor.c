#include "binary_trees.h"


size_t depth(const binary_tree_t *tree);
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If there are no common ancestors, the function returns NULL.
 * Otherwise, it returns
 *         a pointer to the lowest common ancestor of the two nodes.
 *
 * Description: This function finds the lowest common ancestor of
 * two nodes in a binary tree.
 *              It takes two pointers, `first` and `second`,
 *              which point to the two nodes.
 *              If there are no common ancestors,
 *              the function returns NULL. Otherwise, it
 *              compares the positions of the two nodes
 *              relative to each other and their parents
 *              to determine the lowest common ancestor.
 *              The function also uses the `depth` function
 *              to find the depth of each node.
 *              It returns a pointer to the lowest common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	first_parent = first->parent;
	second_parent = second->parent;

	if (first_parent == second_parent)
		return ((binary_tree_t *)first_parent);
	if (first == second_parent)
		return ((binary_tree_t *)first);
	if (first_parent == second)
		return ((binary_tree_t *)second);

	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first_parent;
	for (second_depth = depth(second); second_depth > 1; second_depth--)
		second = second_parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first_parent == second_parent)
		return ((binary_tree_t *)first_parent);
	if (first == second_parent)
		return ((binary_tree_t *)first);
	if (first_parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}



/**
 * depth - Measures the depth of a node in a binary tree.
 *
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, the function returns 0.
 * Otherwise, it returns the depth of the node.
 *
 * Description: This function measures the depth of a node in a binary tree.
 * It takes a pointer
 *              to the node to measure the depth of as a parameter.
 *              If the node is NULL, the
 *              function returns 0. Otherwise,
 *              it recursively traverses the tree from the given
 *              node towards its parent,
 *              incrementing the depth count at each recursive call.
 *              The function returns the depth of the node.
 */
size_t depth(const binary_tree_t *tree)
{
	binary_tree_t *parent_node;

	parent_node = tree->parent;

	return (parent_node != NULL ? 1 + depth(parent_node) : 0);
}
