/*
 * sentinel.c
 *
 *  Created on: Apr 30, 2014
 *      Author: celine
 */


/*
 * MGsentinel.c
 *
 *  Created on: Apr 29, 2014
 *      Author: celine
 */

#include <stdio.h>
int main (void)

{
	float gallons, miles, average, overall, totalG, totalM;
	int counter;

	counter = 0;
	totalG = 0;
	totalM = 0;

	printf("Please enter the gallons used: (Enter -1 to end)\n");
	scanf("%f", &gallons);



	while (gallons != -1){
		printf("Please enter the miles driven: \n");
			scanf("%f", &miles);
		average = miles / gallons;
		printf("The miles/gallons for this tank is : %.6f \n", average);

		counter = counter + 1;
		totalG = totalG + gallons;
		totalM = totalM + miles;
		printf("\nPlease enter the gallons used: (Enter -1 to end)\n");
			scanf("%f", &gallons);
	}

	if (counter != 0){
		overall = totalM / totalG;

			printf("The overall average miles/gallon is: %.6f \n", overall);
	}
	else {
		printf("No values were entered.\n");
	}


	return 0;
}
