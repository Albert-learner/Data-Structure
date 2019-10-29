#include "Minheap.h"

int main()
{
	Minheap MH;
	int tmp = 0;
	cout << "(9 2 5 3 8)" << endl;
	cout << "Program Initiation" << endl;
	MH.insert_minheap(9);
	MH.insert_minheap(2);
	MH.insert_minheap(5);
	MH.insert_minheap(3);
	MH.insert_minheap(8);

	cout << "Now Heap : ";
	MH.display();

	if (MH.isEmpty())
	{
		cout << "Heap is Empty in MAIN" << endl;
	}
	else
	{
		while (1)
		{
			cout << "1. insert_Minheap 2. delete_Minheap 3. isEmpty 4. isFull 5. level 6. display 7. Quit" << endl;
			cout << "ют╥б > ";
			cin >> tmp;

			switch (tmp)
			{
			case 1:
				cout << "insert > ";
				cin >> tmp;
				MH.insert_minheap(tmp);
				MH.display();
				break;
			case 2:
				cout << MH.delete_minheap() << " is deleted" << endl;
				MH.display();
				break;
			case 3:
				cout << (MH.isEmpty() ? "Heap is Empty" : "Heap is not Empty") << endl;
				break;
			case 4:
				cout << (MH.isFull() ? "Heap is Full" : "Heap is not Full") << endl;
				break;
			case 5:
				MH.level();
				break;
			case 6:
				MH.display();
				break;
			case 7:
				cout << "Program End" << endl;
				exit(1);
			default:
				cout << "Not regular cost, Please re-input the cost" << endl;
				break;
			}
		}
	}
	return 0;
}