#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to find height.
 * Return: Height of the tree [SUCCESS] or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_ht = 0;
	size_t right_ht = 0;

	if ((tree == NULL) ||
	(tree->left == NULL && tree->right == NULL))
		return (0);

	left_ht = binary_tree_height(tree->left);
	right_ht = binary_tree_height(tree->right);

	if (left_ht > right_ht)
		return (left_ht + 1);
	return (right_ht + 1);
}
