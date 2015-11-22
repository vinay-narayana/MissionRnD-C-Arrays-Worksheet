/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, j,temp;
	if (len <= 0 || Arr==NULL)
		return NULL;
	for (i = 0; Arr[i] <= Arr[i + 1] && i<len-1; i++);
	for (j = len-1; Arr[j] >= Arr[j - 1] && j>0; j--);
	if (i != len - 1)
	{
		temp = Arr[i];
		Arr[i] = Arr[j];
		Arr[j] = temp;
	}
}