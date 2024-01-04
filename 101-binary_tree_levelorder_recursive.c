#include "binary_trees.h"


ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));
/**
 * binary_tree_levelorder - Performs a level-order
 * traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: This function traverses a binary tree
 * in level-order and calls the
 * provided function for each node visited.
 * It starts at the root node and visits
 * each level from left to right,
 * calling the function on each node encountered.
 * The function takes two parameters:
 * the current node's value and any other data
 * required by the function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;
	int status = 1;

	func(tree->n);
	children = get_children(children, tree);
	if (children == NULL)
	{
		status = 0;
	}

	if (status)
	{
		levels_rec(children, func);
		free_list(children);
	}
	else
	{
		printf("Error: Unable to get children.\n");
	}
}

/**
 * levels_rec - Recursive helper function for level-order traversal.
 * @head: Pointer to head of linked list with nodes at one level.
 * @func: Pointer to a function to call for each node.
 *
 * Description: This function is a recursive helper
 * function for the level-order traversal.
 * It takes a linked list of nodes representing
 * the current level and calls the provided
 * function on each node. It then appends
 * the children nodes to a new linked list and
 * recursively calls itself on the children
 * list to traverse the next level.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;
	int status = 1;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
		if (children == NULL)
		{
			status = 0;
		}
	}
	if (status)
	{
		levels_rec(children, func);
		free_list(children);
	}
	else
	{
		printf("Error: Unable to get children.\n");
	}
}

/**
 * get_children - Appends children of a parent
 * node to a linked list.
 * @head: Pointer to head of the linked list
 * where children will be appended.
 * @parent: Pointer to the node whose
 * children we want to append.
 * Return: Pointer to the head of the
 * linked list of children.
 *
 * Description: This function takes a parent node
 * and appends its children nodes
 * (if they exist) to a linked list. It returns
 * the head of the updated linked list.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	binary_tree_t *temp;

	if (parent->left)
	{
		temp = parent->left;
		head = append(head, temp);
	}
	if (parent->right)
	{
		temp = parent->right;
		head = append(head, temp);
	}
	return (head);
}

/**
 * append - Adds a new node at the end of a linked list.
 * @head: Pointer to the head of the linked list.
 * @btnode: Pointer to the binary tree node to append.
 * Return: Pointer to the head of the updated linked list.
 *
 * Description: This function adds a new node at
 * the end of a linked list. It takes
 * the head of the list and a binary tree node,
 * creates a new node with the binary
 * tree node, and appends it to the end of the list.
 * It returns the head of the updated list.
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new_node = NULL, *last_node = NULL;
	int node_counter;

	new_node = malloc(sizeof(*new_node));
	if (new_node)
	{
		new_node->node = btnode;
		new_node->next = NULL;
		if (!head)
			head = new_node;
		else
		{
			for (last_node = head; last_node && last_node->next;
					last_node = last_node->next)
			{
				node_counter++;
			}
			last_node->next = new_node;
		}
	}
	return (head);
}
/**
 * free_list - Frees all the nodes in a linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Description: This function frees all the nodes in
 * a linked list. It takes the head
 * of the list and iteratively frees each
 * node until the list is empty.
 */
void free_list(ll *head)
{
	ll *ptr = NULL;
	ll *next = NULL;

	do {
		next = head->next;
		free(head);
		head = next;
	} while (head);
}
