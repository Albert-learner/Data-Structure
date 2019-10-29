#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
	ifstream in;
	string line;
	int totalWordCnt = 0;
	in.open("lab0-2.dat");

	while (getline(in, line))
	{
		istringstream sin(line);
		string word;
		char c;
		int wordCnt = 0;
		while (getline(sin, word, ' '))
		{
			if (sin.get() == '\n')
				break;
			wordCnt++;
		}
		cout << line << endl;
		cout << "The number of words : " << wordCnt << "\n";
		totalWordCnt += wordCnt;
	}
	cout << "Total Number of Words : "<< totalWordCnt<< endl;
	return 0;
}