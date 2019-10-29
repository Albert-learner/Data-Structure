#include "LAB3.h"
#include <fstream>
#include <string>

int main()
{
	ifstream in;

	in.open("lab3.txt");

	if (in.fail())
	{
		cout << "File Open Failed" << "\n";
		exit(1);
	}

	string text;
	char temp;

	while (getline(in, text))
	{
		Stack stack;
		bool endflag = 0;
		cout << text << "\t";
		for (int i = 0; i < text.length(); i++)
		{
			if (text[i] == '(' || text[i] == '{' || text[i] == '[')
				stack.push(text[i]);
			else if (text[i] == ')' || text[i] == '}' || text[i] == ']')
			{
				if (stack.IsEmpty())
				{
					cout << "UnBalanced," << "\t";
					cout << "Right parentheses are more than left parentheses" << "\n";
					break;
				}
				else
				{
					temp = stack.pop();
					if (temp == '(' && text[i] == ')')
					{
						continue;
					}
					else if (temp == '{' && text[i] == '}')
					{
						continue;
					}
					else if (temp == '[' && text[i] == ']')
					{
						continue;
					}
					else
					{
						endflag = 1;
						cout << "UnBalanced," << "\t";
						cout << "Mismatched parentheses are : " << temp << ", " << text[i] << "\n";
						break;
					}
				}
			}
			else
				continue;
		}

		if (endflag)
		{
			cout << "\n";
			continue;
		}
		if (stack.IsEmpty())
		{
			cout << "Balanced" << "\n";
		}
		else
		{
			cout << "UnBalalced," << "\t";
			cout << "Left parentheses are more than right parentheses" << "\n";
		}
		cout<<"\n";
	}
	in.close();
	return 0;
}


