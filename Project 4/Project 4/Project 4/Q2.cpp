// Question 2

#include <iostream>
using namespace std;

void Base2();
short a, n, I;

int main()
{

	_asm
	{
		mov ax, 0110 1010 0010 1111;
		call Base2;
		
	}


	return 0;
}

void Base2()
{
	short x = 1 << 15, t; n = a;
	for (int i = 1; i <= 16; ++i)
	{
		t = n & x;
		if (t == 0)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
		if (I % 4 == 0)
		{
			cout << ” “;
		}
		n = n << 1;
	}
	a = n; //save the original value of a
	cout << endl;
}