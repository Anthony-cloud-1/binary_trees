#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of a node.
 * @parent: Pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node [SUCCESS], NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rt_child;

	if (parent == NULL)
		return (NULL);

	rt_child = binary_tree_node(parent, value);
	if (rt_child == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		rt_child->right = parent->right;
		parent->right->parent = rt_child;
	}
	parent->right = rt_child;

	return (rt_child);
}
