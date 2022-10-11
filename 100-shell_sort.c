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
	size_t i, incr;

	incr = 1;
	while (incr <= (size - 1) / 9)
		incr = (3 * incr) + 1;

	while (incr >= 1)
	{
		for (i = incr; i < size; i++)
		{
			t = array[i];
			for (j = (i - incr); j >= 0 && t < array[j]; j -= incr)
				array[j + incr] = array[j];

			array[j + incr] = t;
		}
		incr /= 3;
		print_array(array, size);
	}
}
