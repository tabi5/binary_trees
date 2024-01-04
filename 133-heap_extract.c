#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree.
 *
 * This function takes a pointer to the root
 * node of a binary tree and calculates the
 * height of the tree. The height of a binary
 * tree is defined as the number of edges
 * on the longest path from the root to a leaf node.
 * The function recursively calculates
 * the height by traversing the left and right subtrees
 * and adding 1 for each level
 * visited. The height of an empty tree is 0.
 *
 * @tree: Pointer to the root node of the tree
 * to measure the height.
 *
 * Return: The height of the tree or 0 if the tree is NULL.
 */
size_t tree_height(const heap_t *tree)
{
	size_t left_tree_height = 0;
	size_t right_tree_height = 0;
	size_t max_height;

	if (!tree)
		return (0);

	if (tree->left)
		left_tree_height = 1 + tree_height(tree->left);

	if (tree->right)
		right_tree_height = 1 + tree_height(tree->right);
	max_height = (left_tree_height > right_tree_height)
		? left_tree_height
		: right_tree_height;

	return (max_height);
}

/**
 * tree_size_h - Measures the sum of heights of a binary tree.
 *
 * This function takes a pointer to the root
 * node of a binary tree and calculates the
 * sum of heights of the tree. The sum of heights
 * is defined as the sum of the heights
 * of all the individual nodes in the tree.
 * The function recursively calculates the
 * sum of heights by traversing the left and
 * right subtrees and adding 1 for each level
 * visited. The sum of heights of an empty tree is 0.
 *
 * @tree: Pointer to the root node of the
 * tree to measure the sum of heights.
 *
 * Return: The sum of heights of
 * the tree or 0 if the tree is NULL.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t left_tree_size = 0;
	size_t right_tree_size = 0;
	size_t total_size;

	if (!tree)
		return (0);

	if (tree->left)
		left_tree_size = 1 + tree_size_h(tree->left);

	if (tree->right)
		right_tree_size = 1 + tree_size_h(tree->right);

	total_size = left_tree_size + right_tree_size;
	return (total_size);
}

/**
 * _preorder - Performs pre-order traversal on a binary tree.
 *
 * This function performs a pre-order traversal on a binary tree.
 * It takes a pointer to
 * the root node of the tree, a pointer to the last
 * node visited during traversal, and
 * the height of the tree. The function recursively
 * traverses the tree in pre-order
 * fashion and updates the last visited node when
 * the desired height is reached.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @node: Pointer to the last node visited during traversal.
 * @height: The height of the tree.
 *
 * Return: No return value.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	heap_t *left_subtree, *right_subtree;
	size_t new_height;

	if (!tree)
		return;

	if (!height)
		*node = tree;
	new_height = height - 1;

	left_subtree = tree->left;
	right_subtree = tree->right;

	_preorder(left_subtree, node, new_height);
	_preorder(right_subtree, node, new_height);
}

/**
 * heapify - Heapifies a Max Binary Heap.
 *
 * This function takes a pointer to a Max Binary
 * Heap and performs the heapify operation
 * to restore the heap property. It compares the
 * node with its children and swaps values
 * until the heap property is satisfied.
 *
 * @root: Pointer to the root node of the binary heap.
 *
 * Return: No return value.
 */
void heapify(heap_t *root)
{
	int node_value;
	heap_t *current_node, *child_node;

	if (!root)
		return;

	current_node = root;

	while (1)
	{
		if (!current_node->left)
			break;
		if (!current_node->right)
			child_node = current_node->left;
		else
		{
			if (current_node->left->n > current_node->right->n)
				child_node = current_node->left;
			else
				child_node = current_node->right;
		}
		if (current_node->n > child_node->n)
			break;
		node_value = current_node->n;
		current_node->n = child_node->n;
		child_node->n = node_value;
		current_node = child_node;
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 *
 * This function extracts the root node from a Max Binary Heap.
 *
 *It takes a double pointer
 * to the heap root. The function returns the value of
 * the extracted node and updates the
 * heap structure accordingly. It replaces the root node
 * with the last node in the heap,
 * performs heapify to maintain the heap property, and frees
 * the memory of the extracted node.
 *
 * @root: Double pointer to the heap root.
 *
 * Return: The value of the extracted node.
 **/
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *heap_root, *node_to_extract;
	heap_t *node_parent;

	if (!root || !*root)
		return (0);
	heap_root = *root;
	extracted_value = heap_root->n;
	if (!heap_root->left && !heap_root->right)
	{
		*root = NULL;
		free(heap_root);
		return (extracted_value);
	}

	_preorder(heap_root, &node_to_extract, tree_height(heap_root));

	heap_root->n = node_to_extract->n;
	node_parent = node_to_extract->parent;
	if (node_parent->right)
		node_parent->right = NULL;
	else
		node_parent->left = NULL;
	free(node_to_extract);
	heapify(heap_root);
	*root = heap_root;
	return (extracted_value);
}
