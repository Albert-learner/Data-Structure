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
			cout << "�Է��� �����ʹ� ? " << endl;
			cin >> num;
			insertKey(num);
			break;
		case 2:
			cout << "������ �����ʹ� ? " << endl;
			cin >> num;
			deleteKey(num);
			break;
		case 3:
			printMatrix();
			break;
		case 4:
			cout << "ã�� �����ʹ� ? " << endl;
			cin >> num;
			finding(num);
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
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