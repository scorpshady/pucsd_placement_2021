/*
Given N calculate the Nth fibonacci number. 

A Fibonacci sequence is such that each number is the sum of the two preceding ones starting from 0 and 1. 
F[0] = 0 F[1] = 1
F[n] = F[n-1] + F[n-2]
[0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 
28657, 46368, 75025, 121393, 196418, 317811, 514229]


Your program must accept the parameter n from the command line and print the output to the console 
Sample ./a.out 0     Output 0
Sample ./a.out 12    Output 144
Sample ./a.out 27    Output 196418

Print the result for n as 13, 21, 31, 47, 61, 85

BONUS: Given N calculate the Nth even fibonacci number
Examples
Sample ./a.out 0    Output 0
Sample ./a.out 1    Output 2
Sample ./a.out 2    Output 8
Sample ./a.out 3    Output 34

Print the result for n as 3, 10, 22, 26
*/

#include<stdio.h>
#include<stdlib.h>


int fib(int num)
{
	int prev1 = 0;
	int prev2 = 1;
	int sum = 0;
	int i;
	for(i = 0; i <= num; i++)
	{
		if(i != 0 && i != 1)
		{
			sum  = prev1 + prev2;                  //sum = 1
			prev1 = prev2;
			prev2 = sum;
			
		}

	}                                                                   // time comp: O(n)
	return sum;                                     
}


int nthfib(int num)
{
	int cnt = 0;
	int prev1 = 0;
	int prev2 = 1;
	int sum = 0;
	int i;
	for(i = 0; i >= 0 ; i++)
	{
		if(i != 0 && i <= num != 1)
		{
			sum  = prev1 + prev2;                  //sum = 1
			prev1 = prev2;
			prev2 = sum;
			
		}
		if(sum % 2== 0 && sum != 0)
		{
			cnt++;
		}
		if(cnt == num)
		{
			break;
		}

	}                                                                   // time comp: O(n)
	return sum;       
}




void main()
{
	printf("Enter the number for calculating Nth fibonacci number\n");
	int number = 0;
	scanf("%d", &number);

	int result = fib(number);

	printf("\nThe fibonacci number is %d" ,result);



	printf("\nEnter the number for calculating Nth even fibonacci number\n");
	int number1 = 0;
	scanf("%d", &number1);

	int result1 = nthfib(number1);

	printf("\nThe fibonacci number is %d" ,result1);


	
}