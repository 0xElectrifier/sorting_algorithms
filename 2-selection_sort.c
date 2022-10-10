#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *			`Selection sort` algorithm.
 * @array: array to be sorted
 * @size: length of @array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jmin;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		jmin  = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jmin])
				jmin = j;
		}
		if (jmin != i)
		{
			temp = array[i];
			array[i] = array[jmin];
			array[jmin] = temp;

			print_array(array, size);
		}
	}
}
