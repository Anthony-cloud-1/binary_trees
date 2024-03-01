#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array.
 *
 * @array: a ptr to the 1st element of the array to be converted.
 * @size: the number of elements in the array.
 * Return: a ptr to the root node of the created AVL tree, NULL [failure].
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index_1, index_2;

	if (array == NULL)
		return (NULL);

	for (index_1 = 0; index_1 < size; index_1++)
	{
		for (index_2 = 0; index_2 < index_1; index_2++)
		{
			if (array[index_2] == array[index_1])
				break;
		}
		if (index_2 == index_1)
		{
			if (avl_insert(&tree, array[index_1]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}