#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t index, jayindex;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (jayindex = 0; jayindex < index; jayindex++)
		{
			if (array[jayindex] == array[index])
				break;
		}
		if (jayindex == index)
		{
			if (bst_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}