#include "sort.h"

/**
 * partition - implements the `Lomuto partition scheme`
 * @array: array to sort
 * @size: size of @array
 * @low: the lower bound of the @array, usually 0
 * @high: the higher bound of @array, usually length(array) - 1
 *
 * Return: the pivot index
 */
int partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot, i, j, temp;

	i = low - 1;
	pivot = array[high - 1];

	for (j = low; j < (high - 1); j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;

			print_array(array, size);
		}
		
	}

	return ();
}



/**
 * quick_sort - sorts an array of integers in ascending order using the
 *		`Quick sort` algorithm
 * @array: array to be sorted
 * @size: size of @array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t low, high;
	int p, *array2;

	low = 0;
	high = size - 1;
	p = partion(array, size, low, high);
	if (p == high)
		return;

	array2 = (int *)&array[p+1];

	quick_sort(array, p + 1);
	quick_sort(array2, size - (p+1));
}
