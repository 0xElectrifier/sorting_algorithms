#include "sort.h"

/**
 * partition - implements the `Lomuto partition scheme`
 * @array: array to sort
 * @size: length of @array
 * @low: the lower bound of the @array, usually 0
 * @high: the higher bound of @array, usually length(array) - 1
 *
 * Return: the pivot index
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j, temp;

	i = low - 1;
	pivot = array[high];

	for (j = low; j < (high); j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;

				print_array(array, size);
			}
		}
	}

	i++;
	if (array[i] != pivot)
	{
		temp = pivot;
		array[high] = array[i];
		array[i] = temp;

		print_array(array, size);
	}

	return (i);
}

/**
 * qSort - sorts an array of integers in ascending order using the
 *		`Quick sort` algorithm
 * @array: array to be sorted
 * @size: size of @array
 * @low: the lower bound of the array, usually 0
 * @high: the higher bound of the array, usually length(array) - 1
 *
 * Return: nothing
 */
void qSort(int *array, size_t size, int low, int high)
{
	int p;

	if (low >= high || low < 0)
		return;

	p = partition(array, size, low, high);

	qSort(array, size, low, p - 1);
	qSort(array, size, p + 1, high);
}

/**
 * quick_sort - initializes the recursive `quickSort` function
 * @array: array to be sorted
 * @size: size of @array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size == 0)
		return;

	low = 0;
	high = size - 1;
	qSort(array, size, low, high);
}
