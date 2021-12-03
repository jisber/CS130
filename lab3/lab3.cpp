//Jacob Isber
//My friend Chase from Tennessee Tech helped me with this lab over discord.
//Chris(TA) also helped me.
//Revision 1.6
#include <cstdio>
#include <string.h>
#include <string>

using namespace std;

struct Rooms {

	string header, direction;
	int temp[4] = {-1, -1, -1, -1};

};

int main(int argc, char *argv[]) {
	char *str;
	Rooms *room;
	int RN = 0;
	int i = 0;
	char input;
	FILE *fin;

	if(argc != 2) {
		printf("Incorrect amount of arguments\n");
		return -1;
	}

	str = new char[256];

	fin = fopen(argv[1], "r");
		if(fin == nullptr) {
			perror("File was not open\n");
			return -1;
		}
		
	while( nullptr != (fgets(str, 255, fin))) {
		if(strcmp(str, "~\n")==0)
			RN++;
	}

	RN = RN / 3;


	room = new Rooms[RN];

	fseek(fin, 0, SEEK_SET);

	//int i = 0;
	
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
	
	char arrow;
	int temp1;


		sscanf(str, "%c %d\n", &arrow, &temp1);
		
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
				room[i].temp[2] = temp1;
				break;
			}
		}
			i++;
	}
		
		fclose(fin);
		
	i = 0;

		do {
			printf("> ");
			scanf("%c", &input);

		switch(input) {

			case 'l':
			case 'L':
				printf("%s", room[i].header.c_str());
				printf("%s\n", room[i].direction.c_str());
				printf("Exits: ");
				if(room[i].temp[0] != -1) 
					printf("n ");
				if(room[i].temp[1] != -1) 
					printf("e ");
				
				if(room[i].temp[2] != -1) 
					printf("s");
				
				if(room[i].temp[3] != -1) 
					printf("w ");
				
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
				}
		if(input != 'q') 
			printf("\n");

	}
		while(input != 'q');

		delete [] str;
		delete [] room;

		

		return 0;
}
					






