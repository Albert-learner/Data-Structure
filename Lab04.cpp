#include <iostream>
using namespace std;

/*
Fibonacci 수열을 재귀함수로 하여 최종값 출력
*/

int Fibo(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main(void)
{
	int num;
	cin >> num;
	cout << Fibo(num)<<endl;
}
