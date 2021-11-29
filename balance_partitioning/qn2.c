/*
Balance partitioning of an array

Consider a sequence of N integers where the Kth value is defined as (2K + 4)
Sample values [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28 ...] 

Input N as the length of this sequence, return the index I such that sum of all values to left of I
 is as close as possible to sum of the values to the right.

Sample ./a.out 10     Output: 7    

Explanation
Sequence: N = 10 
[4, 6, 8, 10, 12, 14, 16, 18, 20, 22]

Partitioning at I = 6
Partitions [4, 6, 8, 10, 12, 14] and [18, 20, 22]  
Left sum 54
Right sum 60

Calculate the balance partition for N as 50, 1000, 10000, 100000
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long sum = 0;

long findsum(int *arr, int start, int end) // end exclude end
{
	int i = 0;
	 sum = 0;

	for (i = start ; i <= end; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int fn1(int *arr, int len)
{
	long i, a = 0, b = 0, leftsum = 0, rightsum = 0, d = INT_MAX;
	int resind = 0;
	for (i = 1; i < len - 1; i++)
	{
		a = findsum(arr, 0, i - 1);
		b = findsum(arr, i + 1, len - 1);

		int c = abs(a - b);

		if (c < d)
		{
			resind = i;
			d = c;
			leftsum = a;
			rightsum = b;                 // I could print the leftsum and rightsum also here for more clarity.
		}
	}

	//printf("%d      %d\n", leftsum, rightsum);          //commented this, it was to check to working of program.
	return resind;
}

void main()
{
	printf("Give us the length of the list\n");
	int len = 0;
	scanf("%d", &len);           // here we will input all the input one by one, and it gives us the op

	int list[len];

	int i;

	for (i = 0; i < len; i++)
	{
		list[i] = (2 * i) + 4;
	}

	//display list
	/*
	for (i = 0; i < len; i++)
	{
		printf("%d ", list[i]);
	}
	*/

	// now make a fn to find the index

	int index = fn1(list, len);

	printf("\n\nOutput: %d", index);
}
