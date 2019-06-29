/* 
	Source: 
	https://www.stdio.vn/articles/con-tro-ham-trong-cc-51 
	https://www.cprogramming.com/tutorial/
*/

#include <iostream>     
using namespace std;

/*
Một con trỏ hàm có thể khởi tạo theo mẫu sau:

<kiểu trả về> (*<tên con trỏ>)(<danh sách đối số>);

Ví dụ: void (*pfunc1)(int);
*/

void Ham1(int a, int b) {
	cout << "\na + b = " << (a+b);
}

// Truyền hàm vào hàm
typedef void(*Func_int)(int a, int b);
void foo(Func_int fun, int a, int b)
{
	fun(a, b);
}

// Truyền hàm vào hàm trực tiếp
void foo2(void(*Func_int)(int a, int b), int a, int b)
{
	(*Func_int) (a, b);
}

int main()
{
	// Địa chỉ chủa hàm main
	cout << "Dia chi cua ham main: " << main;
	// Con con trỏ hàm Main
	int(*pMain)();
	pMain = &main;
	cout << "\nGia tri cua con tro pMain: " << pMain;

	// Con trỏ hàm Ham1
	void(*pHam1)(int a, int b);
	pHam1 = &Ham1; // Viết pHam1 = Ham1 cũng OK
	Ham1(1, 2);

	// Sử dụng con trỏ hàm
	(*pHam1)(100, 200);
	pHam1(222, 333);

	// Truyền hàm vào hàm
	foo(&Ham1, 2000, 3000);
	// Không cần dùng & cũng đc
	foo2(Ham1, 8888, 1111);

	getchar();
	return 0;
}