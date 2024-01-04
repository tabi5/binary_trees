#include "binary_trees.h"
/**
 * create_tree - Recursively creates an
 * AVL tree from a sorted array.
 *
 * This function recursively creates an
 * AVL tree from a sorted array of integers.
 * It takes a pointer to the current node
 * the input array, the size of the array,
 * and a mode indicating whether to add nodes
 * on the left or right side of the
 * current node. The function divides the array
 * into two halves and adds the middle
 * element as a new node to the AVL tree. It then
 * recursively creates the left and
 * right subtrees by calling itself with the
 * appropriate parameters.
 *
 * @node: A double pointer to the current
 * node in the AVL tree.
 * @array: The input array of integers.
 * @size: The size of the array.
 * @mode: An integer indicating whether to
 * add nodes on the left (1) or right (2).
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t middle;
	avl_t *new_node;

	if (size == 0)
		return;

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	if (mode == 1)
	{
		new_node = binary_tree_node(*node, array[middle]);
		(*node)->left = new_node;
		create_tree(&((*node)->left), array, middle, 1);
		create_tree(&((*node)->left), array + middle + 1, (size - 1 - middle), 2);
	}
	else
	{
		new_node = binary_tree_node(*node, array[middle]);
		(*node)->right = new_node;
		create_tree(&((*node)->right), array, middle, 1);
		create_tree(&((*node)->right), array + middle + 1, (size - 1 - middle), 2);
	}
}
/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array.
 *
 * This function creates an AVL tree from a sorted array of integers.
 * It initializes
 * the root node as NULL and then calls the create_tree
 * function to recursively build
 * the AVL tree. The create_tree function adds the middle
 * element of the array as the
 * root node and recursively creates the left and right subtrees.
 *
 * @array: The input array of integers.
 * @size: The size of the array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL if the size
 *         of the array is 0.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t middle;
	avl_t *new_root;

	if (size == 0)
		return (NULL);

	middle = (size / 2);
	middle = (size % 2 == 0) ? middle - 1 : middle;

	new_root = binary_tree_node(root, array[middle]);
	root = new_root;

	create_tree(&root, array, middle, 1);
	create_tree(&root, array + middle + 1, (size - 1 - middle), 2);

	return (root);
}
