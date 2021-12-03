//Jacob Isber
//lab1
//July 10th, 2019

#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]) {
//accepts number of arguments and error checks
	if(argc < 3) { 
		printf("Not enough arguments\n");
		return 1;
	}
	else if(argc > 3) {
		printf("Too many arguments\n");
		return 2;
	}

	float i;
	double j;
//Scans user input from argv and argc
	sscanf(argv[1], "%f", &i);

	sscanf(argv[2], "%lf", &j);

	float k;
	unsigned long l;

	printf("Enter two numbers: ");
//Scans user inputs 
	scanf("%f %lu", &k, &l);
//Alters users inputs
	float AddVal1 = 123.45;
	float AddVal2 = 5000;
	float AddVal3 = 12345.678;
	unsigned long AddVal4 = 712;

	AddVal1 += i;
	AddVal2 += k;
	AddVal3 += j;
	AddVal4 += l;
	
//Prints 
	printf("%-8.2f %011.0f %-11.0lf %07lu\n ", AddVal1, AddVal2, AddVal3, AddVal4);
	printf("\n");


	




	return 0;
}

