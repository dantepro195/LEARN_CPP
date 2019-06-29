/*
Source:
https://vietjack.com/cplusplus/cac_lop_luu_tru_trong_cplusplus.jsp
https://docs.microsoft.com/en-us/cpp/cpp/extern-cpp?view=vs-2019
*/

#include <iostream>   

/*
Lớp lưu trữ extern trong C/C++ được dùng để cung cấp một tham chiếu của một biến toàn cục được nhìn thấy bởi TẤT CẢ các file chương trình. 
Khi bạn sử dụng 'extern', biến không thể được khởi tạo, khi nó trỏ tới tên biến tại một vị trí lớp lưu trữ mà đã được định nghĩa trước đó.

Khi bạn có nhiều file và bạn định nghĩa một biến hay hàm toàn cục trong một file và cũng muốn dùng nó trong các file khác, 
thì extern được dùng trong file khác để cung cấp tham chiếu của biến hay hàm được định nghĩa. 
Cần nhớ rằng, extern dùng để khai báo một biến hay hàm toàn cục trong file khác.

Lớp lưu trữ extern được dùng phổ biến khi có hai hoặc nhiều file chia sẻ cùng biến hay hàm toàn cục.
*/
extern void funcA(); // FileA.cpp
extern void funcB(char* str); // FileB.cpp
extern void printVars(); // FileA.cpp
extern int varA; // FileA.cpp
extern int varB; // FileB.cpp

/** 
	extern "C" and extern "C++" function declarations 
**/

//  Cause everything in the specified
//  header files to have C linkage.
extern "C" {
//  add your #include statements here
#include <stdio.h>
}
//  Declare the two functions ShowChar
//  and GetChar with C linkage.
extern "C" {
	char ShowChar(char ch);
	char GetChar(void);
}
//  Define the two functions
//  ShowChar and GetChar with C linkage.
extern "C" char ShowChar(char ch) {
	putchar(ch);
	return ch;
}
extern "C" char GetChar(void) {
	char ch;
	ch = getchar();
	return ch;
}
/* (Check Properties > Linker > Input > lib_c.lib ) */
extern "C++" {
	void lib_cpp_function();
}
/* (Check Properties > Linker > Input > lib_cpp.lib ) */
extern "C" {
	void lib_c_function();
}

int main()
{
	/* Only compile this project with Debug > x64 */

	// printVars được định nghĩa ở FileA.cpp
	printVars();
	// funcB được định nghĩa ở FileB.cpp
	funcB("This is function of FileB");
	// funcA được định nghĩa ở FileA.cpp
	funcA();
	printVars();
	varA = 888;
	varB = 999;
	printVars();

	// Call function from link library (Check Properties > Linker > Input )
	lib_c_function();
	lib_cpp_function();

	// Call from extern "C"
	ShowChar('\n');
	ShowChar('a');
	GetChar();
	//getchar();
	return 0;
}