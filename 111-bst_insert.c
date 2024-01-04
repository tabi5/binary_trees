#include "binary_trees.h"
/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 * @tree: A double pointer to the root node of
 * the BST to insert the value.
 * @value: The value to be inserted into the BST.
 *
 * Return: A pointer to the created node, or NULL on failure.
 *
 * Description: This function inserts a value into
 * a Binary Search Tree (BST).
 * It takes a double pointer to the root node of the BST (`tree`)
 * and the value to be inserted (`value`).
 * If the `tree` pointer is not NULL, the function performs
 * the insertion based on the value and returns
 * a pointer to the newly created node. If the `tree`
 * pointer is NULL, a new node is created with the given
 * value and becomes the root of the BST.
 * If the value is less than the current node's value, the function
 * recursively calls itself on the left subtree.
 * If the value is greater than the current node's value,
 * the function recursively calls itself on the right subtree.
 * If the value already exists in the BST,
 * the function returns NULL indicating failure.
 * If memory allocation fails, the function also returns NULL.
 * The function uses the `binary_tree_node` function
 * to create new nodes and updates the `left` or `right`
 * pointer of the parent node accordingly.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new, *parent;

	if (tree == NULL)
		return (NULL);

	curr = *tree;
	parent = NULL;

	while (curr != NULL)
	{
		parent = curr;
		if (value < curr->n)
			curr = curr->left;
		else if (value > curr->n)
			curr = curr->right;
		else
			return (NULL); /* value already exists in the tree */
	}

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent == NULL) /* tree was empty */
		*tree = new;
	else if (value < parent->n)
		parent->left = new;
	else
		parent->right = new;

	return (new);
}

