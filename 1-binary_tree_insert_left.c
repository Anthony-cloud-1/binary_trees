#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: Pointer to the node to insert the left child in.
 * @value: The value to store the new node.
 * Return: A pointer to the created node [SUCCESS], NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *lt_child;

	if (parent == NULL)
		return (NULL);

	lt_child = binary_tree_node(parent, value);
	if (lt_child == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		lt_child->left = parent->left;
		parent->left->parent = lt_child;
	}
	parent->left = lt_child;

	return (lt_child);
}
