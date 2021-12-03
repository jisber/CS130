//Jacob Isber
//My friend Chase from Tennessee Tech helped me with this lab over discord.
//Chris(TA) also helped me with this code
//Lab 3
//Revision 2.6

#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>

using namespace std;

//This is struct Rooms
struct Rooms {

	string direction, header;
	int temp[4] = {-1, -1, -1, -1};

};

//Start of main()
int main(int argc, char *argv[]) {

//Declared variable and pointers
	char *str;
	Rooms *room;
	int RN = 0;
	char input;
	FILE *fin;

	int i = 0;
//Error checks arg count
	if(argc != 2) {
		printf("Incorrect amount of arguments\n");
		return -1;
	}

//Allocates 256 bytes to str
	str = new char[256];

//Opnes and error checks to see if file was open
	fin = fopen(argv[1], "r");
		if(fin == nullptr) {
			perror("File was not open\n");
			return -1;
		}

//Reads in the entire file and chekcs the buffer to see if it contains ~
	while( nullptr != (fgets(str, 255, fin))) {
		string line(str);
		if(line == "~\n")
		{
			RN++;
		}
	}
	RN = RN / 3;

//Declared data type with allocated memory 
	room = new Rooms[RN];

//Seeks to the beginning of the file
	fseek(fin, 0, SEEK_SET);


//Moves information thats being inputed into the struct
	while(i != RN) {

		while(string(fgets(str, 255, fin)) != "~\n") {
			if(str == nullptr) 
				break;
				room[i].header = str;
			}
		
		
		while(string(fgets(str, 255, fin)) != "~\n") {
			if(str == nullptr) 
				break;
				room[i].direction += str;
			}
	
		while(string(fgets(str, 255, fin)) != "~\n") {
			if(str == nullptr) 
				break;

//New variables to allow a switch to be used 

	char arrow;
	int temp1;


		sscanf(str, "%c %d", &arrow, &temp1);
		
		switch(arrow) {
			case 'n' :
			case 'N' :
				room[i].temp[0] = temp1;
				break;
			case 'e':
			case 'E':
				room[i].temp[1] = temp1;
				break;
			case 's':
			case 'S':
				room[i].temp[2] = temp1;
				break;
			case 'w':
			case 'W':
				room[i].temp[3] = temp1;
				break;
			}
		}
			i++;
	}
//Closes the file		
		fclose(fin);

//Resets I to zero. (Honestly do not know why I had to do this but I kept getting seg faults if i didn't)
		i = 0;

//Start to the game and user interface
		do {
			printf("> ");
			scanf("%c", &input);

		switch(input) {

			case 'l':
			case 'L':
				printf("%s", room[i].header.c_str());
				printf("%s\n", room[i].direction.c_str());
				printf("Exits: ");
				if(room[i].temp[0] != -1) {
					printf("n ");
				}
				if(room[i].temp[1] != -1) {
					printf("e ");
				}
				if(room[i].temp[2] != -1) {
					printf("s ");
				}
				if(room[i].temp[3] != -1) {
					printf("w ");
				}
					break;
				case 'q':
				case 'Q':
					break;
				case 'n':
				case 'N':
					if(room[i].temp[0] != -1){
						i = room[i].temp[0];
						printf("You moved NORTH");
					}
					else
						printf("You can't go NORTH!");
					break;
				case 'e':
				case 'E':
					if(room[i].temp[1] != -1){
						i = room[i].temp[1];
						printf("You moved EAST.");
					}
					else
						printf("You can't go EAST!");
					break;
				case 's':
				case 'S':
					if(room[i].temp[2] != -1) {
						i = room[i].temp[2];
						printf("You moved SOUTH.");
					}
					else
						printf("You can't go SOUTH!");
					break;
				case 'w':
				case 'W':
					if(room[i].temp[3] != -1) {
						i = room[i].temp[3];
						printf("you moved WEST.");
					}
					else
						printf("You can't go WEST!");
					break;
				}
		if(input != 'q') 
			printf("\n");

	}
		//Ensures the while loop continues until user inputes q
		while(input != 'q');

//Deletes all new memory that was allocated
		delete [] str;
		delete [] room;

		

		return 0;
}
					






