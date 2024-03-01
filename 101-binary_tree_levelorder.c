#include "binary_trees.h"

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
levelorder_queue_t *create_node(binary_tree_t *node);
void pint_push(binary_tree_t *node, levelorder_queue_t *precede,
		levelorder_queue_t **ending, void (*func)(int));
void free_queue(levelorder_queue_t *precede);
void pop(levelorder_queue_t **precede);

/**
 * binary_tree_levelorder - Goes through a bin-tree by level-order traversal.
 *
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *precede, *ending;

	if (tree == NULL || func == NULL)
		return;

	precede = ending = create_node((binary_tree_t *)tree);
	if (precede == NULL)
		return;

	while (precede != NULL)
	{
		pint_push(precede->node, precede, &ending, func);
		pop(&precede);
	}
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
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 *
 * @node: The binary tree node to print and push.
 * @precede: A double pointer to the precede of the queue.
 * @ending: A double pointer to the ending of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *precede,
		levelorder_queue_t **ending, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(precede);
			exit(1);
		}
		(*ending)->next = new;
		*ending = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL)
		{
			free_queue(precede);
			exit(1);
		}
		(*ending)->next = new;
		*ending = new;
	}
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 *
 * @precede: A pointer to the precede of the queue.
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
 * pop - Pops the precede of a levelorder_queue_t queue.
 *
 * @precede: A double pointer to the precede of the queue.
 */
void pop(levelorder_queue_t **precede)
{
	levelorder_queue_t *tmp;

	tmp = (*precede)->next;
	free(*precede);
	*precede = tmp;
}