/*
 * HorT.c
 *
 *  Created on: May 9, 2014
 *      Author: celinemarcelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip (void);


int main (void){
	int counter, tCounter, hCounter;
	int side;

	srand(time(NULL));

	tCounter = 0;
	hCounter = 0;
	counter = 0;

	while (counter < 100){
		side = flip ();

		switch (side){
			case 0:
				++tCounter;
				++counter;
				printf("Tails\n");
				break;

			case 1:
				++hCounter;
				++counter;
				printf("Heads\n");
				break;
			}
	}

	printf("Total tails are: %d\nTotal heads are: %d\n", tCounter, hCounter);


return 0;
}

int flip (void){

	int result;
	result = rand() % 2;
	return result;
	}
