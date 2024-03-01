#include "binary_trees.h"

bst_t *_bst_rmv(bst_t *root, int value);
int _rmv_type(bst_t *root);
int successor(bst_t *node);
void _bal_fac(avl_t **tree);

/**
 * avl_remove - removes a node from an AVL tree.
 *
 * @root: a ptr to the root of the AVL tree.
 * @value: the value to be removed.
 * Return: a ptr to the new root node after removing and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) _bst_rmv((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	_bal_fac(&root_a);

	return (root_a);
}

/**
 * _bst_rmv - remove a node from a BST tree.
 *
 * @root: ptr to the root of the tree.
 * @value: vale to be removed at the node.
 * Return: the modified tree or NULL if root is NULL.
 */
bst_t *_bst_rmv(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		_bst_rmv(root->left, value);
	else if (value > root->n)
		_bst_rmv(root->right, value);
	else if (value == root->n)
	{
		type = _rmv_type(root);
		if (type != 0)
			_bst_rmv(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * successor - find the successor in the right subtree.
 *
 * @node: ptr to the root of subtree.
 * Return: min value of subtree or 0 if node is NULL.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}


/**
 * _rmv_type - removes a node depending on its children.
 *
 * @root: ptr to the node to be removed.
 * Return: 0 - has no children or other value if it has.
 */
int _rmv_type(bst_t *root)
{
	int new_val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}

		free(root);
		return (0);
	}
	else
	{
		new_val = successor(root->right);
		root->n = new_val;
		return (new_val);
	}
}

/**
 * _bal_fac - measures balance factor of a AVL.
 *
 * @tree: double ptr to the tree.
 * Return: the balance factor.
 */
void _bal_fac(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	_bal_fac(&(*tree)->left);
	_bal_fac(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}