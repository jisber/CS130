//Jacob Isber
//Lab 2
#include <cstdio>
#include <stdio.h>

#include <iostream>
using namespace std;


//This is our bitset struct
class Bitset {
	unsigned long m_value;
public:
	Bitset();	
	Bitset(unsigned long initial_value);
	bool test(int bit) const;
	void set(int bit);
	void clear(int bit);
	void reset();
	void print() const;
};
	

int main() { 

	Bitset mybs { 0xe7 };
        mybs.print();
        printf("\n");
		
        mybs.set(44);
        mybs.set(45);
        mybs.clear(1);
        mybs.set(13);
        mybs.clear(14);
        mybs.print();
        printf("\n");

        mybs.reset();
        mybs.print();
        printf("\n");{ 

		}
	
	return 0;
		
}
Bitset::Bitset() {

}

//This assignes m_value to the initial value
Bitset::Bitset(unsigned long initial_value) {
	
	m_value = initial_value;
}

//This test out number to check for 0 and 1
bool Bitset::test(int bit) const {

	
	int k = (m_value >> bit) & 1;	
	if(k == 1) {
		return true;
	}
	else
		return false;

}

//This sets the number
void Bitset::set(int bit) {

	 m_value |= 1UL << bit;

}
//This clears the number
void Bitset::clear(int bit) {

	m_value &= ~(1UL << bit);

}
//This resets the number
void Bitset::reset() {
	m_value = 0;
} 
//This prints the number and underscores
void Bitset::print() const {

	
for(int i = 63; i >= 0; i--) {
	if((i % 4  == 3) && (i != 63)) {
		printf("_");
	}
	printf("%d" , test(i));

	 
	}
	
}


