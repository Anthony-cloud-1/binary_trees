#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *turn, *tempo;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	turn = tree->left;
	tempo = turn->right;
	turn->right = tree;
	tree->left = tempo;
	if (tempo != NULL)
		tempo->parent = tree;
	tempo = tree->parent;
	tree->parent = turn;
	turn->parent = tempo;
	if (tempo != NULL)
	{
		if (tempo->left == tree)
			tempo->left = turn;
		else
			tempo->right = turn;
	}

	return (turn);
}