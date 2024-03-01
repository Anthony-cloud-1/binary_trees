#include "binary_trees.h"

int binary_tree_is_complete(const binary_tree_t *tree);
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *precede);
void push(binary_tree_t *node, levelorder_queue_t *precede,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **precede);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{

	levelorder_queue_t *precede, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	precede = tail = create_node((binary_tree_t *)tree);
	if (precede == NULL)
		exit(1);

	while (precede != NULL)
	{
		if (precede->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(precede);
				return (0);
			}
			push(precede->node->left, precede, &tail);
		}
		else
			flag = 1;
		if (precede->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(precede);
				return (0);
			}
			push(precede->node->right, precede, &tail);
		}
		else
			flag = 1;
		pop(&precede);
	}
	return (1);
}

/**
 * create_node - Creates a new levelorder_queue_t node.
 *
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 *
 * @precede: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *precede)
{
	levelorder_queue_t *tmp;

	while (precede != NULL)
	{
		tmp = precede->next;
		free(precede);
		precede = tmp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 *
 * @node: The binary tree node to print and push.
 * @precede: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *precede,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(precede);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 *
 * @precede: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **precede)
{
	levelorder_queue_t *tmp;

	tmp = (*precede)->next;
	free(*precede);
	*precede = tmp;
}