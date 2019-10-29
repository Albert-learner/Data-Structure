#include <iostream>
using namespace std;

int Factorial(int cost)
{
	if (cost == 1)
	{
		cout << cost << "= ";
		return 1;
	}
	else
	{
		cout << cost << "+";
		return cost + Factorial(cost - 1);
	}
}

int iter_Factorial(int cost)
{
	int fact = 0;
	for (int i = 1; i <= cost; i++)
	{
		fact += i;
	}
	return fact;
}

int main()
{
	int num;
	cin >> num;

	cout << Factorial(num) << endl;
	cout << iter_Factorial(num) << "\n";
	return 0;
}