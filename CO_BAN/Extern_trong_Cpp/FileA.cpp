#include <iostream>     

int varA = 100; // declaration and definition
extern int varB;

extern void funcB(char* str);

void funcA() {
	funcB("This is function of FileA");
	varB = 2000;
}

void printVars() {
	std::cout << "\nFileA: varA = " << varA << " var B = " << varB << "\n";
}