#include <iostream>
using namespace std;

int recur_add(int n1, int n2)
{
	if (n1 == 0)
	{
		cout << "add(" << n1 << "," << n2 << ")\t";
		cout << "Result=" << n1 + n2 << "\n";
		return n1 + n2;
	}
	else
	{
		cout << "add(" << n1 << "," << n2 << ")-> ";
		recur_add(n1 - 1, n2 + 1);
	}
}

int recur_dif(int n1, int n2)
{
	if (n1 == 0)
	{
		cout << "Diff(" << n1 << ", " << n2 << ")\t";
		cout << "Result = " << n1 + n2 << "\n";
		return n1 + n2;
	}
	else
	{
		cout << "Diff(" << n1 << ", " << n2 << ")-> ";
		recur_dif(n1 - 1, n2 - 1);
	}
}

int Factorial(int num)
{
	if (num == 1)
	{
		cout << num << "= ";
		return 1;
	}
	else
	{
		cout << num << " + ";
		return num + Factorial(num - 1);
	}
}

int main()
{
	int num1, num2, cost;
	cout << "Enter number1 : ";
	cin >> num1;
	cout << "Enter number2 : ";
	cin >> num2;
	cout << "Addition Result is : " << recur_add(num1, num2) << "\n";
	cout << "Difference Result : " << recur_dif(num1, num2) << "\n";

	cout << "Enter a number : ";
	cin >> cost;
	cout <<"Result is: "<< Factorial(cost)<<"\n";
	return 0;
}