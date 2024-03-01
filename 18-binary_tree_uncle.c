#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node.
 *
 * @node: ptr to the node to find the uncle.
 * Return: ptr to the uncle, or NULL if parent/node is NULL
 *+ or the node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if ((node == NULL) || (node->parent == NULL))
		return (NULL);

	/*Go to the parent*/
	node = node->parent;
	if (node->parent == NULL)
		return (NULL);

	/*Find parent's sibling*/
	/*If left-child is not NULL, return it*/
	if ((node->parent->left != NULL) && (node->parent->left != node))
		return (node->parent->left);

	/*If right-child is not NULL, return it*/
	if ((node->parent->right != NULL) && (node->parent->right != node))
		return (node->parent->right);

	return (NULL);
}