#pragma warning (disable : 4715)
#include <iostream>
using namespace std;

int recur_add(int n1, int n2)
{
	if (n1 == 0)
	{
		cout << "add(" << n1 << "," << n2 << ")\n";
		cout << "sum=" << n1 + n2 << "\n";
		return n1 + n2;
	}
	else
	{
		cout << "add(" << n1 << "," << n2 << ")-> ";
		recur_add(n1 - 1, n2 + 1);
	}
}

int iter_add(int n, int m)
{
	int sum;
	while (n > 0)
	{
		cout << "n=" << n << " m=" << m << "; ";
		n -= 1;
		m += 1;
	}
	cout << "n=" << n << " " << "m=" << m << ";\n";
	sum = n + m;
	cout << sum << "\n";
	return sum;
}

int main()
{
	int num1, num2, n, m;
	cin >> num1 >> num2;
	recur_add(num1, num2);
	cin >> n >> m;
	iter_add(n, m);
	return 0;
}