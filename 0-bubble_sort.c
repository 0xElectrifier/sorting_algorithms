#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 *		Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of @array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, swapped = 1;

	if (size < 2)
		return;

	while (swapped)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if  (array[i - 1] > array[i])
			{
				tmp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = tmp;
				print_array(array, size);
				swapped = 1;
			}
		}
	}
}
