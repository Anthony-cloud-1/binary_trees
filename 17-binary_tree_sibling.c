#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 *
 * @node: ptr to the node whose sibling is to be found.
 * Return: ptr to the sibling or NULL if parent/node is NULL
 *+ or the node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if ((node == NULL) || (node->parent == NULL))
		return (NULL);

	/*Go to the parent If left-child is not NULL, return it*/
	if ((node->parent->left != NULL) && (node->parent->left != node))
		return (node->parent->left);

	/*If right-child is not NULL, return */
	if ((node->parent->right != NULL) && (node->parent->right != node))
		return (node->parent->right);

	return (NULL);
}