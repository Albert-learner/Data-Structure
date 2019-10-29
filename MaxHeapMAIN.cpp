#include "MaxHeap.h"

int main()
{
	MaxHeap MX;
	int temp = 0;
	cout << "Program Initiation" << endl;

	if (MX.isEmpty())
	{
		cout << "Heap is empty" << "\n";
	}
	MX.insert_maxheap(8);
	MX.insert_maxheap(6);
	MX.insert_maxheap(4);
	MX.insert_maxheap(2);
	MX.insert_maxheap(5);
	MX.insert_maxheap(3);

	cout << "Now Heap : ";
	MX.display();
	if (MX.isEmpty())
	{
		cout << "Heap is Empty in MAIN" << "\n";
	}
	else
	{
		while (1)
		{
			cout << "1. insert_Maxheap 2. delete_Maxheap 3. isEmpty 4. isFull 5. level 6. Quit" << endl;
			cout << "ют╥б > ";
			cin >> temp;

			switch (temp)
			{
			case 1:
				cout << "insert > ";
				cin >> temp;
				MX.insert_maxheap(temp);
				MX.display();
				break;
			case 2:
				cout << MX.delete_maxheap() << " is deleted" << endl;
				MX.display();
				break;
			case 3:
				cout << (MX.isEmpty() ? "Heap is Empty" : "Heap is not Empty") << endl;
				break;
			case 4:
				cout << (MX.isFull() ? "Heap is Full" : "Heap is not Full") << endl;
				break;
			case 5:
				MX.level();
				break;
			case 6:
				exit(1);
			default:
				cout << "Not regular cost, Please re-input the cost" << "\n";
				break;
			}
		}
	}
	return 0;
}