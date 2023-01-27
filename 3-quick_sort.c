#include "sort.h"

/**
 * separate - Split the array to do the quicksort
 * @array: The array to implement quicksort
 * @one: The minimum value
 * @end: The maximum value
 * @size: The size of the array
 * Return: The pivot
*/

int separate(int *array, int one, int end, size_t size)
{
	int i, j = one, pivote = array[end], temp = 0;

	for (i = one; i < end; i++)
	{
		if (array[i] <= pivote)
		{
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (j != i)
				print_array(array, size);
			j++;
		}
	}
	temp = array[j];
	array[j] = array[i];
	array[i] = temp;
	if (j != i)
		print_array(array, size);
	return (j);
}

/**
 * recursive_sort - Implements the recursion of quicksort
 * @array: the arrray
 * @one: the minimum value
 * @end: the maximun value
 * @size: size of the array
*/


void recursive_sort(int *array, int one, int end, size_t size)
{
	int pivote;

	if (one < end)
	{
		pivote = separate(array, one, end, size);
		recursive_sort(array, one, pivote - 1, size);
		recursive_sort(array, pivote + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array with quicksort methods
 * @array: the array
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	recursive_sort(array, 0, size - 1, size);
}
