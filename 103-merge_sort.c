#include "sort.h"

/**
 * merge_subA - Sort a subA of integers.
 * @subA: A subA of an array of integers to sort.
 * @buff: A buffer to store the sorted subA.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subA(int *subA, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subA + front, mid - front);

	printf("[right]: ");
	print_array(subA + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subA[i] < subA[j]) ? subA[i++] : subA[j++];
	for (; i < mid; i++)
		buff[k++] = subA[i];
	for (; j < back; j++)
		buff[k++] = subA[j];
	for (i = front, k = 0; i < back; i++)
		subA[i] = buff[k++];

	printf("[Done]: ");
	print_array(subA + front, back - front);
}

/**
 * mrg_sort_recurs - Implement the merge sort algorithm through recursion.
 * @subA: A subA of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subA.
 * @back: The back index of the subA.
 */
void mrg_sort_recurs(int *subA, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		mrg_sort_recurs(subA, buff, front, mid);
		mrg_sort_recurs(subA, buff, mid, back);
		merge_subA(subA, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	mrg_sort_recurs(array, buff, 0, size);

	free(buff);
}
