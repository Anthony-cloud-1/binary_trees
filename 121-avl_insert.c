#include "binary_trees.h"

size_t _calc_height(const binary_tree_t *tree);
avl_t *_avl_ins_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
int _balance(const binary_tree_t *tree);

/**
 * avl_insert - inserts a value in an AVL Tree.
 *
 * @tree: a double ptr to the root node of the AVL tree.
 * @value: the value to store in the node.
 * Return: ptr to the created node[success], NULL [failure].
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	_avl_ins_recursive(tree, *tree, &new, value);

	return (new);
}

/**
 * _avl_ins_recursive - inserts a value into an AVL tree recursively
 *
 * @tree: a double ptr to the root node of the AVL tree.
 * @parent: the parent node of current working node
 * @new: a double ptr to store the new node
 * @value: the value to insert into the AVL tree.
 * Return: ptr to new root [success], NULL [failure].
 */
avl_t *_avl_ins_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int b_fac; /*Balance factor*/

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = _avl_ins_recursive(&(*tree)->left, *tree, new, value);

		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = _avl_ins_recursive(&(*tree)->right, *tree, new, value);

		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	b_fac = _balance(*tree);
	if (b_fac > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_fac < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_fac > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_fac < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * _balance - calculates the balance factor of a binary tree.
 *
 * @tree: a ptr to the root node of the binary tree.
 * Return: balance factor or 0 if tree is NULL.
 */
int _balance(const binary_tree_t *tree)
{
	return (tree != NULL ? _calc_height(tree->left) -
	_calc_height(tree->right) : 0);
}

/**
 * _calc_height - measures the height of a binary tree.
 *
 * @tree: a ptr to the root node of the tree to measure the height.
 * Return: height of the tree or 0 if tree is NULL.
 */
size_t _calc_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lt = 0, rt = 0;

		lt = tree->left ? 1 + _calc_height(tree->left) : 1;
		rt = tree->right ? 1 + _calc_height(tree->right) : 1;
		return ((lt > rt) ? lt : rt);
	}
	return (0);
}