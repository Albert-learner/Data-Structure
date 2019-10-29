#pragma warning (disable : 4715)
#include <iostream>
using namespace std;

int Fibo(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (Fibo(n - 1) + Fibo(n - 2));
}

int iter_Fibo(int n)
{
	int fir = 0, sec = 1, thi = 0;
	for (int i = 0; i < n; i++)
	{
		cout << fir << " ";
		thi = fir + sec;
		fir = sec;
		sec = thi;
	}
	return fir;
}

int main()
{
	int cost;
	cin >> cost;
	cout << Fibo(cost) << endl;
	cout << "\n";

	cout << iter_Fibo(cost) << "\n";
	return 0;
}