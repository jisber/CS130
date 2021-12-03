//Jacob Isber
//Chris(TA) helped me with this lab. 
//Cosc130 Lab4
//Revision 1.8

#include <cstdio>
#include <iostream>

using namespace std;


int main(int argc, char *argv[]) 
{
//Error check to make sure enough arguments were put in
	if(argc > 4) {
		printf("Too many arguments");
		return -1;
	}
	if(argc < 4) {
		printf("Not enough arguments");
		return -2;
	}

//Declared variables
	FILE *file;
	char data, dkey; 
	int loc, lockey, j;
	char *str;

//Scans in both arguments and stores them into the variables
	sscanf(argv[2], "%c", &dkey);
	sscanf(argv[3], "%d", &lockey);

//Opens the file
	file = fopen(argv[1], "rb");

//Seeks to the end of the file to get the total size of the file.	
	fseek(file, 0, SEEK_END);

//This takes the total size of the file and divides it by 8 to get it into bytes that way you are not waisting memory, then stores into j;
	j = ftell(file) / 8;

//Seeks back to the front of the file.
	fseek(file, 0, SEEK_SET);

//Declaring a char pointer called str with the total size of the file.
	str = new char[j];

//Runs the for loop that way it prints everything on the line.
for(int l = 0; l < j; l++){
	fread(&data, 1, 1, file);
	fseek(file, 3, SEEK_CUR);
	fread(&loc, 1, 4, file);
	data ^= dkey;
	loc ^= lockey;

//Error checks the size of the index.
	if(loc >= j || loc < 0) {
		printf("Error decoding chunk %d, decoded index %d, but max chunk is %d.\n", l, loc, j);
		return -3;
	}
	str[loc] = data;

}

//Closes the file.
	fclose(file);

//Prints the data.
	printf("%s", str);

//Delets the allocated str to prevent memory leaks	
	delete[] str;

 return 0;
}
