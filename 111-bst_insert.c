#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *present, *new;

	if (tree != NULL)
	{
		present = *tree;
		if (present == NULL)
		{
			new = binary_tree_node(present, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		if (value < present->n)
		{
			if (present->left != NULL)
				return (bst_insert(&present->left, value));
			new = binary_tree_node(present, value);
			if (new == NULL)
				return (NULL);
			return (present->left = new);
		}
		if (value > present->n)
		{
			if (present->right != NULL)
				return (bst_insert(&present->right, value));
			new = binary_tree_node(present, value);
			if (new == NULL)
				return (NULL);
			return (present->right = new);
		}
	}

	return (NULL);
}