#include "binary_trees.h"

int _binary_tree_is_leaf(const binary_tree_t *node);
int _binary_tree_height(const binary_tree_t *tree);
int _binary_tree_is_perfect(const binary_tree_t *tree);


/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 *
 * @tree: ptr to the root node.
 * Return: 1 - tree isComplete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int lef_H, rig_H;
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);

	if (_binary_tree_is_leaf(tree))
		return (1);

	l = tree->left;
	r = tree->right;
	lef_H = _binary_tree_height(l);
	rig_H = _binary_tree_height(r);

	if (lef_H == rig_H)
	{
		if (binary_tree_is_complete(r) && _binary_tree_is_perfect(l))
			return (1);
	}
	else if (lef_H == rig_H + 1)
	{
		if (binary_tree_is_complete(l) && _binary_tree_is_perfect(r))
			return (1);
	}

	return (0);
}



/**
 * _binary_tree_height - measures the height of a binary tree
 *
 * @tree: a ptr to the root node of the tree to find height.
 * Return: height of the tree or 0 if tree is NULL.
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int lef_H = 0, rig_H = 0;

	if (tree == NULL)
	{
		return (0);
	}

	/*Recursively call the func to calc. the height*/
	lef_H = _binary_tree_height(tree->left);
	rig_H = _binary_tree_height(tree->right);

	/*Compare for the maximum depth*/
	if (lef_H > rig_H)
		return (lef_H + 1);
	return (rig_H + 1);
}

/**
 * _binary_tree_is_leaf - checks if a node is a leaf.
 *
 * @node: ptr to the node to be checked.
 * Return: 1 - isLeaf, 0 - isNotLeaf || node is NULL
 */
int _binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}

	return (0);
}

/**
 * _binary_tree_is_perfect - checks if a binary tree is perfect.
 *
 * @tree: ptr to the root node of the tree to check
 * Return: 1 - if isPerfect, 0 - ifNotPerfect or tree is NULL
 */
int _binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (1);
	l = tree->left;
	r = tree->right;
	if (_binary_tree_is_leaf(tree))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (_binary_tree_height(l) == _binary_tree_height(r))
	{
		if (_binary_tree_is_perfect(l) && _binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}