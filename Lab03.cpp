#include <iostream>
using namespace std;

/*
Factorial 함수를 재귀함수로 하여 더하는 값으로 출력
*/

int Facto(int n)
{
	if (n == 1)
	{
		cout << n << " = ";
		return 1;
	}
	else
	{
		cout << n << '+';
		return n + Facto(n - 1);
	}
}

int main(void)
{
	int n;
	cin >> n;
	cout << Facto(n)<< endl; // cout <<Facto(n)<<endl; 왜 2번 나오지??? 위에 Facto함수에서 한 번 출력했잖아
	return 0;
}