#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common
 * ancestor of two nodes.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors, the function returns NULL.
 * Otherwise, it returns
 *         a pointer to the lowest common
 *         ancestor of the two nodes.
 *
 * Description: This function finds the lowest common
 * ancestor of two nodes in a binary tree.
 *              It takes two pointers, `first` and `second`,
 *              which point to the two nodes.
 *              If there are no common ancestors, the function returns NULL.
 *              Otherwise, it
 *              recursively searches for the lowest common
 *              ancestor by traversing the tree
 *              from the given nodes towards their parents.
 *              The function returns a pointer
 *              to the lowest common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	first_parent = first->parent;
	second_parent = second->parent;

	if (first == second_parent || !first_parent ||
			(!first_parent->parent && second_parent))
		return (binary_trees_ancestor(first, second_parent));
	else if (first_parent == second || !second_parent ||
			(!second_parent->parent && first_parent))
		return (binary_trees_ancestor(first_parent, second));
	return (binary_trees_ancestor(first_parent, second_parent));
}
