/*
	Source:
	https://daynhauhoc.com/t/lam-quen-voi-cach-viet-chuong-trinh-c-tren-nhieu-file/74161
	https://www.stdio.vn/articles/chi-thi-tien-xu-ly-trong-cc-512
*/
#include <iostream>

/* Yêu cầu Complier tìm định nghĩa của hàm func_file_A trong file khác (hàm này được định nghĩa trong FileA.cpp) */
void func_file_A(); // func_file_A được định nghĩa trong FileA.obj
extern int a; // biến a được định nghĩa trong FileA.obj

/* #include đơn giản là COPY PASTE toàn bộ nội dung của FileB.h vào đây --> yêu cầu Complier tìm định nghĩa của các hàm trong FileB.h */
#include "FileB.h" // Tìm định nghĩa của hàm func_file_B trong file FileB.obj
#include "FileC.h" // Tìm định nghĩa của hàm func_file_C trong file FileC.obj

int main()
{
	func_file_A();
	func_file_B();
	func_file_C();
	a = b + c;
	getchar();
	return 0;
}
/*
            |-------------------------- Header file -------------------------------------|
		    |                        |                        |                          |
		Copy header             Copy header              Copy header                Copy header  
		    |                        |                        |                          |
         FileA.cpp                FileB.cpp                main.cpp                  FileC.cpp   
		    |                        |                        |                          |
	      Compile    	          Compile   	           Compile   	              Compile   
	 	    |                        |                        |                          |
		FileA.obj                 FileB.obj                 main.obj                   FileC.obj
	    	|                        |                        |                          |
			|                        |                        |                          |
			------------------------------------------------------------------------------
			---------------------------------LINK-----------------------------------------  <========== Standard Runtime Library 
			------------------------------------------------------------------------------ 
			                                   |
											main.exe 
*/