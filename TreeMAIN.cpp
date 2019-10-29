#include "Tree.h"
#include <fstream>

int main()
{
	ifstream fin;
	fin.open("Tree.txt");

	if (fin.fail())
	{
		cout << "File open Error" << endl;
		exit(1);
	}
	else
	{
		int cnt;
		fin >> cnt;

		for (int i = 0; i < cnt; i++)
		{
			string s;
			cout << "수식 입력 ("<<i+1<<")"<<endl;
			fin >> s;

			Tree t(s);
			cout << "Inorder : ";
			t.inorder(t.getRoot());
			cout << endl;
			cout << "PostOrder : ";
			t.postorder(t.getRoot());
			cout << endl;
			cout << "PreOrder : ";
			t.preorder(t.getRoot());
			cout << endl;
			cout << "Evaluation : ";
			cout << t.evalTree(t.getRoot()) << endl;
			cout << "Tree Structure" << endl;
			t.drawTree(t.getRoot());
			cout << endl;
			cout << "------------------------------" << endl;
		}
	}
	return 0;
}