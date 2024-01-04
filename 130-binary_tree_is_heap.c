#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - Checks if all nodes in a binary
 *tree have the root as the maximum value.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if all nodes have the root as
 * the maximum value, 0 otherwise.
 **/
int check_max(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	int left_check = 1, right_check = 1;

	if (!tree)
		return (0);

	current = tree;
	while (current != NULL)
	{
		if (current->left)
		{
			if (current->n <= current->left->n)
				return (0);
			current = current->left;
		}
		else if (current->right)
		{
			if (current->n <= current->right->n)
				return (0);
			current = current->right;
		}
		else
		{
			break;
		}
	}

	return (left_check && right_check);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a heap.
 * @tree: Pointer to the root of the binary tree.
 * Return: 1 if the binary tree is a heap, 0 otherwise.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	const binary_tree_t *current;
	int complete_check, heap_check;

	if (!tree)
		return (0);

	current = tree;
	while (current != NULL)
	{
		if (current->left)
			current = current->left;
		else if (current->right)
			current = current->right;
		else
			break;
	}

	complete_check = (current == NULL) ? 1 : 0;
	if (!complete_check)
		return (0);

	heap_check = check_max(tree);
	return (heap_check);
}

