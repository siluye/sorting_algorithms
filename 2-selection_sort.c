#include "sort.h"

/**
 * selection_sort - Implements the selection sort on an array
 * @array: The array that we wants to sort
 * @size: The size of the array
 * Return: None
*/

void selection_sort(int *array, size_t size)
{

	size_t i = 0, j = 0, k = 0;
	int key = 0, temp = 0;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		key = array[i];
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < key)
			{
				key = array[j];
				k = j;
			}
		}
		if (k != i)
		{
			temp = array[i];
			array[i] = key;
			array[k] = temp;
			print_array(array, size);
		}
	}
}
