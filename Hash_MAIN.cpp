#include "Hash.h"

int main()
{
	int input;
	int num;
	int finish = 0;

	while (1)
	{
		cout << "1. insert 2. delete 3. print 4. find 5. quit" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "입력할 데이터는 ? " << endl;
			cin >> num;
			insertKey(num);
			break;
		case 2:
			cout << "삭제할 데이터는 ? " << endl;
			cin >> num;
			deleteKey(num);
			break;
		case 3:
			printMatrix();
			break;
		case 4:
			cout << "찾을 데이터는 ? " << endl;
			cin >> num;
			finding(num);
			break;
		default:
			cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
			break;
		}
		if (finish)
		{
			break;
		}
	}
	printMatrix();
	return 0;
}