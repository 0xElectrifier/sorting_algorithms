#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order, using the
 *		`Shell sort` algorithm, using the `Knuth sequence`
 * @array: array to be sorted
 * @size: length of @array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int j, t;
	size_t i, gap;

	if (array == NULL)
		return;

	gap = 1;
	while (gap < (size / 3))
		gap = (3 * gap) + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			t = array[i];
			for (j = (i - gap); j >= 0 && t < array[j]; j -= gap)
				array[j + gap] = array[j];

			array[j + gap] = t;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
