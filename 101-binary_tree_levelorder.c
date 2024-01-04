#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new levelorder_queue_t node.
 *
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 *
 * Description: This function creates a new levelorder_queue_t node
 * that contains a binary tree node.
 *              It takes a pointer to the binary tree node as a parameter.
 *              If memory allocation fails,
 *              the function returns NULL. Otherwise,
 *              it allocates memory for the new node, sets its
 *              `node` field to the given binary tree node,
 *              and initializes its `next` field to NULL.
 *              The function returns a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;
	size_t node_size = sizeof(levelorder_queue_t);

	new_node = (levelorder_queue_t *)malloc(node_size);
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 *
 * @head: A pointer to the head of the queue.
 *
 * Description: This function frees a levelorder_queue_t queue.
 * It takes a pointer to the head of
 *              the queue as a parameter. It iterates through the queue,
 *              freeing each node, and
 *              updates the head pointer accordingly.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp_node;
	int is_queue_empty;

	while (head != NULL)
	{
		temp_node = head->next;
		is_queue_empty = (temp_node == NULL) ? 1 : 0;
		free(head);
		head = temp_node;
		if (is_queue_empty)
			break;
	}
}


/**
 * pint_push - Runs a function on a given binary tree node
 * and pushes its children into a levelorder_queue_t queue.
 *
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: This function runs a function on a given binary tree node
 * and pushes its children into a levelorder_queue_t queue.
 *              It takes the binary tree node to process, a double pointer
 *              to the head of the queue, a double pointer to the tail
 *              of the queue, and a pointer to the
 *              function to call on the node.
 *              The function calls the given function on the node's
 *              value, and if the node has a left or right child,
 *              it creates a new levelorder_queue_t node for
 *              each child and appends
 *              them to the queue. If memory allocation fails,
 *              the function frees the queue, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;
	int exit_status = 1;

	func(node->n);
	if (node->left != NULL)
	{
		new_node = create_node(node->left);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(exit_status);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = create_node(node->right);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(exit_status);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}


/**
 * pop - Pops the head of a levelorder_queue_t queue.
 *
 * @head: A double pointer to the head of the queue.
 *
 * Description: This function pops the head of a levelorder_queue_t queue.
 * It takes a double pointer
 *              to the head of the queue as a parameter.
 *              It updates the head pointer to the next node
 *              in the queue and frees the previous head node.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp_node;
	int is_queue_empty;

	temp_node = (*head)->next;
	is_queue_empty = (temp_node == NULL) ? 1 : 0;
	free(*head);
	*head = temp_node;
	if (is_queue_empty)
		return;
}

/**
 * binary_tree_levelorder - Traverses a binary tree
 * using level-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 *
 * Description: This function traverses a binary tree using
 * level-order traversal. It takes a pointer
 *              to the root node of the tree to traverse and
 *              a pointer to a function to call for each node.
 *              The function performs a level-order traversal by
 *              maintaining a queue of nodes to process.
 *              It starts with the root node, pushes it into the queue,
 *              and then iteratively processes
 *              the nodes in the queue, calling the given
 *              function on eachnode's value
 *              and pushing its children into the queue. *
 *              The function continues
 *              this process until the queue is empty,
 *              effectively traversing the tree in level-order.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;
	int new_var1 = 0;
	int new_var2 = 0;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		new_var1++;
		pint_push(head->node, head, &tail, func);
		pop(&head);
		new_var2 = new_var1;
		if (new_var2 % 2 == 10)
		{
			printf("Even iteration: %d\n", new_var2);
		}
	}
}
