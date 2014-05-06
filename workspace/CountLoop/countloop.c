/*
 * countloop.c
 *
 *  Created on: May 7, 2014
 *      Author: celinemarcelo
 */

#include <stdio.h>
int main (void)

{
	int A;
	A = 0;

	while (A <=300000000)
	{
		A += 1;

		if (A % 100000000 ==0)
		{
			printf ("%d\n", A);
		}
	}
return 0;
}
