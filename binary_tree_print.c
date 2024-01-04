#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Stores recursively each
 * level in an array of strings
 *
 * This function recursively stores each
 * level of a binary tree in an array of strings.
 * It takes a pointer to the node to print,
 * the current offset, the depth of the node,
 * and the buffer to store the tree. The function
 * calculates the width of the node's
 * value and recursively calls itself for the left
 * and right subtrees. It then updates
 * the buffer with the node's value and adds appropriate
 * dashes and dots to represent
 * the tree structure. The updated buffer is returned.
 *
 * @tree: Pointer to the node to print.
 * @offset: Offset to print.
 * @depth: Depth of the node.
 * @s: Buffer.
 *
 * Return: Length of the printed tree after processing.
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char buffer[6];
	int node_width, left_offset, right_offset, is_left_child, i;

	if (!tree)
		return (0);
	is_left_child = (tree->parent && tree->parent->left == tree);
	node_width = sprintf(buffer, "(%03d)", tree->n);
	left_offset = print_t(tree->left, offset, depth + 1, s);
	right_offset = print_t(tree->right,
			offset + left_offset + node_width,
			depth + 1,
			s);
	for (i = 0; i < node_width; i++)
		s[depth][offset + left_offset + i] = buffer[i];
	if (depth && is_left_child)
	{
		for (i = 0; i < node_width + right_offset; i++)
			s[depth - 1][offset + left_offset + node_width / 2 + i] = '-';
		s[depth - 1][offset + left_offset + node_width / 2] = '.';
	}
	else if (depth && !is_left_child)
	{
		for (i = 0; i < left_offset + node_width; i++)
			s[depth - 1][offset - node_width / 2 + i] = '-';
		s[depth - 1][offset + left_offset + node_width / 2] = '.';
	}
	return (left_offset + node_width + right_offset);
}

/**
 * _height - Measures the height of a binary tree.
 *
 * This function measures the height of
 * a binary tree starting from the given node.
 * It takes a pointer to the node and recursively
 * calculates the height by comparing
 * the heights of the left and right subtrees.
 * The height of an empty tree is 0.
 *
 * @tree: Pointer to the node to measure the height.
 *
 * Return: The height of the tree starting at the node.
 */

static size_t _height(const binary_tree_t *tree)
{
	size_t left_subtree_height;
	size_t right_subtree_height;
	size_t max_height;

	left_subtree_height = tree->left ? 1 + _height(tree->left) : 0;
	right_subtree_height = tree->right ? 1 + _height(tree->right) : 0;
	max_height = (left_subtree_height > right_subtree_height)
		? left_subtree_height
		: right_subtree_height;

	return (max_height);
}

/**
 * binary_tree_print - Prints a binary tree.
 *
 * This function prints a binary tree in a visually appealing way.
 * It takes a pointer
 * to the root node of the tree to print.
 * The function calculates the height of the tree,
 * allocates memory for a buffer to store the tree,
 * and initializes the buffer with spaces.
 * It then calls the print_t function to populate the buffer
 * with the tree structure.
 * Finally, it prints each line of the buffer
 * and frees the allocated memory.
 *
 * @tree: Pointer to the root node of the tree to print.
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t tree_height, i, j;
	char *row;

	if (!tree)
		return;
	tree_height = _height(tree);
	s = malloc(sizeof(*s) * (tree_height + 1));
	if (!s)
		return;
	for (i = 0; i < tree_height + 1; i++)
	{
		row = malloc(sizeof(**s) * 255);
		if (!row)
			return;
		memset(row, 32, 255);
		s[i] = row;
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < tree_height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
