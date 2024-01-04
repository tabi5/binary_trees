#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);
/**
 * height - Measures the height of a binary tree.
 *
 * This function calculates the height of
 * a binary tree by recursively traversing
 * the tree and counting the number of edges
 * on the longest path from the root
 * to a leaf node.
 *
 * @tree: A pointer to the root node of the
 * tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0.
 * Otherwise, it returns the height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l_height = 0, r_height = 0;
		size_t l_increment = 0, r_increment = 0;

		l_increment = tree->left ? 1 : 0;
		r_increment = tree->right ? 1 : 0;

		l_height = l_increment + binary_tree_height(tree->left);
		r_height = r_increment + binary_tree_height(tree->right);

		return ((l_height > r_height) ? l_height : r_height);
	}
	return (0);
}
/**
 * balance - Measures the balance factor of a binary tree.
 *
 * This function calculates the balance factor of
 * a binary tree by subtracting
 * the height of the right subtree from the height of the left subtree.
 * A balance factor of -1, 0, or 1 indicates a balanced tree.
 *
 * @tree: A pointer to the root node of the
 * tree to measure the balance factor.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise,
 * it returns the balance factor.
 */
int balance(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree != NULL)
	{
		size_t left_height = height(tree->left);
		size_t right_height = height(tree->right);

		balance_factor = left_height - right_height;
	}
	else
	{
		balance_factor = 0;
	}

	return (balance_factor);
}
/**
 * avl_insert_recursive - Inserts a value into
 * an AVL tree recursively.
 *
 * This function inserts a value into an AVL tree recursively.
 * It maintains the balance
 * of the tree by performing rotations as necessary.
 * The new node is inserted based on
 * its value, and the recursive process continues
 * until the correct position is found.
 * The parent node and the new node are passed as parameters
 * to keep track of the parent-child
 * relationship during the insertion process.
 *
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfact;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfact = balance(*tree);
	if (bfact > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfact < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfact > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfact < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}
/**
 * avl_insert - Inserts a value into an AVL tree.
 *
 * This function inserts a value into an AVL
 * tree by calling the recursive insertion function.
 * If the tree is initially empty, it creates a new root node.
 * Otherwise, it calls the recursive
 * insertion function to insert the value into
 * the tree while maintaining the AVL property.
 *
 * @tree: A double pointer to the root node of
 * the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;
	avl_t *inserted_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	inserted_node = avl_insert_recursive(tree, *tree, &new_node, value);
	return (inserted_node);
}
