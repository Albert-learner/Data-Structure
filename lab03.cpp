#include "lab03.h"
#include <fstream>
#include <string>

int main()
{
	ifstream in;

	in.open("lab03.txt");

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
					cout << "InValid" << "\t";
					cout << "(Unbalanced parentheses)" << "\n";
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
						cout << "InValid," << "\t";
						cout << "(Mismatched parentheses)" << "\n";
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
			cout << "Valid" << "\n";
		}
		else
		{
			cout << "InValid" << "\t";
			cout << "(Unbalanced parentheses)" << "\n";
		}
		cout << "\n";
	}
	in.close();
	return 0;
}


