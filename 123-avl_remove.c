#include "binary_trees.h"
/**
 * bal - Balances an AVL tree by performing rotations if necessary.
 *
 * This function checks the balance factor of each node in the AVL tree and
 * performs rotations to balance the tree if a node's balance factor is greater
 * than 1 or less than -1. It recursively balances the tree by traversing each
 * node and applying the appropriate rotation to restore balance.
 *
 * @tree: A double pointer to the root node of the AVL tree to balance.
 */
void bal(avl_t **tree)
{
	int balance_value;
	avl_t *left_subtree, *right_subtree;

	if (tree == NULL || *tree == NULL)
		return;
	left_subtree = (*tree)->left;
	right_subtree = (*tree)->right;
	if (left_subtree == NULL && right_subtree == NULL)
		return;
	bal(&left_subtree);
	bal(&right_subtree);
	balance_value = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance_value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - Finds the minimum value in the right subtree of a BST node.
 *
 * This function finds the minimum value in the right subtree
 * of a given BST node.
 * It recursively searches for the leftmost node in
 * the right subtree to find the
 * minimum value.
 *
 * @node: The BST node to find the successor for.
 *
 * Return: The minimum value in the right subtree, or 0 if the node is NULL.
 */
int successor(bst_t *node)
{
	int left_successor = 0;
	int node_value = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left_successor = successor(node->left);
		if (left_successor == 0)
		{
			node_value = node->n;
			return (node_value);
		}
		return (left_successor);
	}
}
/**
 * remove_type - Removes a node from a BST tree based on its children.
 *
 * This function removes a node from a BST tree
 * based on the type of children it has.
 * If the node is a leaf node (no children),
 * it is simply removed. If the node has
 * only one child, that child is linked to
 * the parent of the node. If the node has
 * two children, the successor node is found and
 * its value replaces the value of the
 * node to be removed. The successor
 * node is then removed from the tree.
 *
 * @root: The node to remove from the BST tree.
 *
 * Return: 0 if the node has no children,
 * or the value of the successor node if it exists.
 */
int remove_type(bst_t *root)
{
	int varnew_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		varnew_value = successor(root->right);
		root->n = varnew_value;
		return (varnew_value);
	}
}
/**
 * bst_remove - Removes a node from a BST tree.
 *
 * This function removes a node with a specific
 * value from a BST tree. It recursively
 * searches for the node to remove and
 * handles different cases based on the number
 * of children the node has.
 * The bst_remove function calls the remove_type function
 * to remove the node and rebalances the tree if necessary.
 *
 * @root: The root of the BST tree.
 * @value: The value of the node to remove.
 *
 * Return: The modified BST tree after the removal,
 * or NULL if the tree is empty or
 *         the node to remove is not found.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int node_type = 0;
	bst_t *left_subtree, *right_subtree;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
	{
		left_subtree = bst_remove(root->left, value);
		root->left = left_subtree;
	}
	else if (value > root->n)
	{
		right_subtree = bst_remove(root->right, value);
		root->right = right_subtree;
	}
	else if (value == root->n)
	{
		node_type = remove_type(root);
		if (node_type != 0)
			bst_remove(root->right, node_type);
	}
	else
		return (NULL);
	return (root);
}
/**
 * avl_remove - Removes a node from an AVL tree.
 *
 * This function removes a node with a specific
 * value from an AVL tree. It calls the
 * bst_remove function to remove the node from
 * the underlying BST tree, and then
 * it balances the AVL tree using the bal function
 * to maintain the AVL property.
 *
 * @root: The root of the AVL tree.
 * @value: The value of the node to remove.
 *
 * Return: The modified AVL tree after the removal,
 * or NULL if the tree is empty or
 *         the node to remove is not found.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *removed_node = NULL;
	avl_t *balanced_tree = NULL;

	removed_node = (avl_t *) bst_remove((bst_t *) root, value);

	if (removed_node == NULL)
		return (NULL);
	bal(&removed_node);
	balanced_tree = removed_node;
	return (balanced_tree);
}
