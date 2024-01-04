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
	heap_t *tree, *new, *parent, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	parent = NULL;
	while (tree != NULL)
	{
		parent = tree;
		for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
			tree = leaves & bit ? tree->right : tree->left;
	}

	new = binary_tree_node(parent, value);
	leaves & 1 ? (parent->right = new) : (parent->left = new);

	flip = new;
	while (flip->parent && (flip->n > flip->parent->n))
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
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
	if (!tree)
		return (0);

	size_t left_tree_size = binary_tree_size(tree->left);
	size_t right_tree_size = binary_tree_size(tree->right);

	return (left_tree_size + right_tree_size + 1);
}
