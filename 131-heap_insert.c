#include "binary_trees.h"
/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * This function inserts a value into a Max Binary Heap.
 * It takes a double pointer
 * to the root node of the heap and the value to be inserted.
 * The function first
 * checks if the root is NULL and creates a new node
 * with the given value if it is.
 * It then traverses the heap to find the appropriate
 * empty slot for insertion based
 * on the binary representation of the number of leaves.
 * The function creates a new
 * node with the value and links it to the empty slot.
 * Finally, it performs a flip
 * operation to ensure that the heap property is maintained,
 * swapping values with
 * the parent node until the parent value exceeds the new value.
 *
 * @root: A double pointer to the root node of the Max Binary Heap.
 * @value: The value to be inserted into the heap.
 *
 * Return: A pointer to the created node.
 *         NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *newNode, *nodeToFlip;
	int treeSize, leafNodes, subtractor, bitValue, treeLevel, tempValue;
	int newVar = 2;
	int varone = 1;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	treeSize = binary_tree_size(tree);
	leafNodes = treeSize;
	for (treeLevel = 0, subtractor = varone; leafNodes >= subtractor;
			subtractor *= newVar, treeLevel++)
		leafNodes -= subtractor;

	for (bitValue = varone << (treeLevel - varone);
			bitValue != varone; bitValue >>= varone)
		tree = leafNodes & bitValue ? tree->right : tree->left;
	newNode = binary_tree_node(tree, value);
	leafNodes & varone ? (tree->right = newNode) : (tree->left = newNode);

	nodeToFlip = newNode;
	for (; nodeToFlip->parent && (nodeToFlip->n > nodeToFlip->parent->n);
			nodeToFlip = nodeToFlip->parent)
	{
		tempValue = nodeToFlip->n;
		nodeToFlip->n = nodeToFlip->parent->n;
		nodeToFlip->parent->n = tempValue;
		newNode = newNode->parent;
	}



	return (newNode);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * This function calculates the size of a binary tree.
 * It takes a pointer to the root
 * node of the binary tree. The size of a binary
 * tree is defined as the total number
 * of nodes in the tree. The function recursively
 * calculates the size by summing up
 * the sizes of the left and right subtrees and
 * adding 1 for the current node.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: The size of the binary tree.
 *         0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t leftTreeSize, rightTreeSize, totalTreeSize, varone = 1;

	if (!tree)
		return (0);

	leftTreeSize = binary_tree_size(tree->left);
	rightTreeSize = binary_tree_size(tree->right);
	totalTreeSize = leftTreeSize + rightTreeSize + varone;

	return (totalTreeSize);
}



