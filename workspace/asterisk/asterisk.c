/*
 * asterisk.c
 *
 *  Created on: May 9, 2014
 *      Author: celinemarcelo
 */

#include <stdio.h>
int main (void)
{
	int a, b, c, d, e, counter;

	printf("Please enter five numbers from 1 - 30.\n");

			scanf("%d", &a);
			scanf("%d", &b);
			scanf("%d", &c);
			scanf("%d", &d);
			scanf("%d", &e);

	if (30 < a|| 30 < b || 30 < c || 30 < d || 30 < e || 0 > a || 0 > b || 0 > c || 0 > d || 0 > e){
		printf("Value/s entered exceed the specified range. Please run program again.\n");
		return 0;
		}
	else{
		printf("The numbers you entered are: %d %d %d %d %d\n\n", a, b, c, d, e);
		}

	counter = 0;

	do{
		++counter;
		printf("*");
		}
	while (counter < a);
		printf ("\n");

	counter = 0;


	do{
		++counter;
		printf("*");
		}
	while (counter < b);
		printf ("\n");

	counter = 0;

	do{
		++counter;
		printf("*");
		}
	while (counter < c);
		printf ("\n");

	counter = 0;

	do{
		++counter;
		printf("*");
		}
	while (counter < d);
		printf ("\n");

	counter = 0;

	do{
		++counter;
		printf("*");
		}
	while (counter < e);
		printf ("\n");


	return 0;
}
