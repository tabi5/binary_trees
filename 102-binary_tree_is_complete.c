#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);
/**
 * create_node - Creates a new node for the level-order queue.
 * @node: The binary tree node to be contained in the new node.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 *
 * Description: This function creates a new
 * node for the level-order queue.
 * It takes a binary tree node as a parameter and
 * returns a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;
	int status = 1;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
	{
		status = 0;
	}

	if (status)
	{
		new->node = node;
		new->next = NULL;
	}
	else
	{
		new = NULL;
	}

	return (new);
}

/**
 * free_queue - Frees the memory allocated for
 * the level-order queue.
 * @head: A pointer to the head of the queue.
 *
 * Description: This function frees the memory
 * allocated for the level-order queue.
 * It takes a pointer to the head of the queue
 * and iteratively frees each node in the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *current = head;
	levelorder_queue_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

/**
 * push - Pushes a binary tree node to the back of
 * the level-order queue.
 * @node: The binary tree node to be pushed.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: This function pushes a binary tree
 * node to the back of the level-order queue.
 * It takes the node to be pushed, a double pointer
 * to the head of the queue, and a double pointer
 * to the tail of the queue. If a memory allocation
 * failure occurs during the creation of a new node,
 * the function frees the entire queue and exits the
 * program with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;
	int status = 1;

	new = create_node(node);
	if (new == NULL)
	{
		status = 0;
	}

	if (status)
	{
		(*tail)->next = new;
		*tail = new;
	}
	else
	{
		free_queue(head);
		exit(1);
	}
}

/**
 * pop - Removes the head of the level-order queue.
 * @head: A double pointer to the head of the queue.
 *
 * Description: This function removes
 * the head of the level-order queue.
 * It takes a double pointer to the head of the queue
 * and frees the memory allocated for the head node.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *next_node;

	if (*head != NULL)
	{
		next_node = (*head)->next;
		free(*head);
		*head = next_node;
	}
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the binary tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: This function checks if a binary
 * tree is complete by performing a level-order traversal
 * using the level-order queue. It takes a pointer to
 * the root node of the binary tree as a parameter.
 * If the tree is NULL or not complete, the function returns 0.
 * If a memory allocation failure occurs during
 * the creation of the level-order queue,
 * the function exits the program with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *queue_head, *queue_tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return 0;

	queue_head = queue_tail = create_node((binary_tree_t *)tree);
	if (queue_head == NULL)
		exit(1);

	while (queue_head != NULL)
	{
		if (queue_head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(queue_head);
				return 0;
			}
			push(queue_head->node->left, queue_head, &queue_tail);
		}
		else
			flag = 1;

		if (queue_head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(queue_head);
				return 0;
			}
			push(queue_head->node->right, queue_head, &queue_tail);
		}
		else
			flag = 1;

		pop(&queue_head);
	}

	return 1;
}
