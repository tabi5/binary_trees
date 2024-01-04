#include "binary_trees.h"
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new node for the level-order traversal queue.
 *
 * @node: The binary tree node to include in the new queue node.
 *
 * Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 *
 * Description: This function creates a new node for the queue used in the
 * level-order traversal of a binary tree.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;
	int status = 0;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		status = -1;

	if (status == 0)
	{
		new->node = node;
		new->next = NULL;
	}

	return (status == 0 ? new : NULL);
}


/**
 * free_queue - Frees a level-order traversal queue.
 *
 * @head: A pointer to the head of the queue.
 *
 * Description: This function frees the memory allocated for a level-order
 * traversal queue used in the binary tree traversal.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * push - Pushes a node to the back of a level-order traversal queue.
 *
 * @node: The binary tree node to push to the queue.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: This function pushes a binary tree node to the back of the
 * level-order traversal queue, updating the head and tail accordingly.
 * If a memory allocation failure occurs, the function exits with status code 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;
	int isCreated = 1;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		isCreated = 0;
	}

	if (isCreated)
	{
		(*tail)->next = new;
		*tail = new;
	}
	else
	{
		exit(1);
	}
}

/**
 * pop - Pops the head of a level-order traversal queue.
 *
 * @head: A double pointer to the head of the queue.
 *
 * Description: This function removes the head of the level-order traversal
 * queue, updating the head pointer accordingly and freeing the memory.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *nextNode;

	nextNode = (*head)->next;
	free(*head);
	*head = nextNode;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: If the tree is NULL or not complete, 0. Otherwise, 1.
 *
 * Description: This function checks if a binary tree is complete by performing
 * a level-order traversal using a queue. It returns 1 if the tree is complete
 * and 0 otherwise. If a memory allocation failure occurs, the function exits
 * with status code 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
