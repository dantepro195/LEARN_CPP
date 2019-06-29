#include <iostream>   

extern int varA;
int varB = 0;

// int varA = 43; // LNK2005! 'varA' already has a definition.
// extern int varA = 10; // LNK2005! 'varA' already has a definition.
void funcB(char* str) {
	std::cout << "\n" << str << "\n";
	varA = 1000;
}