/*
LAB1 20153212 ¿Ã¿Á∫Û
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
	ifstream fin;
	string line;
	int totalWordCnt = 0;
	fin.open("lab0-1.dat");

	if (fin.fail())
	{
		cout << "File Open Failed" << "\n";
		exit(1);
	}

	while (getline(fin, line))
	{
		istringstream sin(line);
		string word;
		int wordCnt = 0;
		while (getline(sin, word, ' '))
		{
			if (sin.get() == '\n')
			{
				break;
			}
			wordCnt++;
		}
		cout << line << "\n";
		cout << '\t'<<"The number of words : " << wordCnt << "\n";
		totalWordCnt += wordCnt;
	}
	cout << "\n";
	cout << "Total Number of Words : " << totalWordCnt << "\n";
	return 0;
}