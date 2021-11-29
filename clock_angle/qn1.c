/*
Calculate the minimum angle between hour hand and minute hand on a standard clock.
  
Your program must accept the parameters from the command line as hour and minute value and return the angle between 
them in degrees rounded off to 2 decimal digits.
Sample ./a.out 09 00   Output 90.00 
Sample ./a.out 03 30   Output 75.00 
Generate the output for 09 00, 03 30, 05 00, 08 45

BONUS: Given the input as HOUR MINUTE SECOND return the minimum angle between the minute and second hand.
Generate the output for 09 00  30, 03 30 45, 05 00 50, 08 45 05

*/

#include<stdio.h>
#include<stdlib.h>


float fn(int hr , int min)
{
	float res = ((hr * 60 * 0.5) + (min  * 0.5)) - (min * 6);
	return abs(res);
}

/*
float fn1(int hr , int min , int sec)
{
	float res = ((hr * 60 * 0.5) + (min  * 0.5) + (hr * 3600 * (1 / 120 ) ) + sec * (1 / 120)) - ((sec * 0.1) + (min * 6));
	return abs(res);
}

*/                           // I was trying the min and sec, but couldnt get the eqn right.
void main()
{
	int hr , min, sec;
	printf("Give the hr\n");
	scanf("%d", &hr);
	printf("\nGive the min\n");
	scanf("%d", &min);

	float res = fn(hr , min);

	printf("\n\n%.2f",res);


/*
	printf(\nGive the min\n);
	scanf("%d", &hr);

	printf("\nGive the sec\n");
	scanf("%d", &sec);

	float res1 = fn1(hr , sec);
	printf("\n\n%.2f", res1);
*/

}