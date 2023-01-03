#include "sort.h"
/**
 * partition - implement the Lomuto partition scheme
 * @arr: pointer to the array
 * @low: initial position
 * @high: last position
 * @size: the lenght of array
 *
 * Return: the next position to validate into array
 */
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1, tmp = 0;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			if (i != j)
				print_array(arr, size);
		}
	}
	tmp = arr[j];
	arr[j] = arr[i + 1];
	arr[i + 1] = tmp;
	if (i + 1 != j)
		print_array(arr, size);
	return (i + 1);
}
/**
 * sorting - recursive function to organize and validate each position of array
 * @arr: pointer to the array
 * @low: initial position
 * @high: last position
 * @size: the lenght of array
 *
 */
void sorting(int *arr, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, size);

		sorting(arr, low, pi - 1, size);
		sorting(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: pointer to the array
 * @size: the lenght of the array
 */
void quick_sort(int *array, size_t size)
{
	int high = size - 1;

	sorting(array, 0, high, size);
}
