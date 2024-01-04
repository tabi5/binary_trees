#include "binary_trees.h"
/**
 * inorder_successor - Returns the minimum value
 * of a binary search tree.
 *
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in the BST.
 *
 * Description: This function returns the minimum
 * value in a binary search tree (BST).
 * It takes a pointer to the root node of the BST to search (`root`).
 * The function traverses
 * the left subtree of the BST until it reaches
 * the leftmost node (which contains the minimum value),
 * and then returns a pointer to that node.
 */
bst_t *inorder_successor(bst_t *root)
{
	bst_t *current_node = root;

	while (current_node->left != NULL)
	{
		current_node = current_node->left;
	}
	return (current_node);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 *
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: This function deletes a node from
 * a binary search tree (BST).
 * It takes a pointer to the root node of the BST (`root`)
 * and a pointer to
 * the node to be deleted from the BST (`node`).
 * The function handles three cases:
 * 1. If the node has no children or only a right child,
 * the function adjusts the
 *    parent and child pointers accordingly and
 * frees the memory occupied by the node.
 * 2. If the node has only a left child,
 * the function adjusts the parent and child
 *    pointers accordingly and frees the memory occupied by the node.
 * 3. If the node has two children, the function
 * finds the in-order successor of the
 *    node (the minimum value in the right subtree),
 * replaces the value of the node
 *    with the value of the successor, and
 * recursively deletes the successor node.
 * The function returns a pointer to the
 * new root node of the BST after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;
	bst_t *leftChild = node->left;
	bst_t *rightChild = node->right;

	/* No children or right-child only */
	if (leftChild == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = rightChild;
		else if (parent != NULL)
			parent->right = rightChild;
		if (rightChild != NULL)
			rightChild->parent = parent;
		free(node);
		return (parent == NULL ? rightChild : root);
	}

	/* Left-child only */
	if (rightChild == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = leftChild;
		else if (parent != NULL)
			parent->right = leftChild;
		if (leftChild != NULL)
			leftChild->parent = parent;
		free(node);
		return (parent == NULL ? leftChild : root);
	}

	/* Two children */
	successor = inorder_successor(rightChild);
	node->n = successor->n;

	return (bst_delete(root, successor));
}
/**
 * bst_remove_recursive - Removes a node from
 * a binary search tree recursively.
 *
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 *
 * Description: This function removes a node
 * from a binary search tree (BST)
 * recursively. It takes a pointer to
 * the root node of the BST to remove a node from
 * (`root`), a pointer to the current node in the BST (`node`),
 * and the value to remove
 * from the BST (`value`). The function recursively
 * searches for the node with the
 * specified value in the BST. If found, it calls
 * the `bst_delete` function to delete
 * the node from the BST. The function returns
 * a pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{

		if (node->n == value)
		{
			return (bst_delete(root, node));
		}

		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		else
			return (bst_remove_recursive(root, node->right, value));
	}

	return (NULL);
}
/**
 * bst_remove - Removes a node from a binary search tree.
 *
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: This function removes a node
 * from a binary search tree (BST).
 * It takes a pointer to the root node of the
 * BST to remove a node from (`root`)
 * and the value to remove from the BST (`value`).
 * The function calls the `bst_remove_recursive`
 * function to remove the node with the specified
 * value from the BST. If the node to be deleted
 * has two children, it is replaced with its first in-order successor.
 * The function returns a
 * pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}

