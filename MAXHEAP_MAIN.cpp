#include "MAXHEAP.h"
using namespace std;

int main()
{
	MaxHeap h;
	int temp = 0;
	cout << "<< Program Initiation>>" << endl;
	if (h.isEmpty())
		cout << "Heap is empty" << endl;
	h.insert_maxheap(8);
	h.insert_maxheap(6);
	h.insert_maxheap(4);
	h.insert_maxheap(2);
	h.insert_maxheap(5);
	h.insert_maxheap(3);

	cout << "Now Heap: ";
	h.display();
	while (true)
	{
		cout << "1. insert_maxheap  2. delete_maxheap  3. isEmpty  4. isFull  5. level 6. Quit" << endl;
		cout << "ют╥б> ";
		cin >> temp;

		switch (temp)
		{
		case 1:
			cout << "insert> ";
			cin >> temp;
			h.insert_maxheap(temp);
			h.display();
			break;
		case 2:
			cout << h.delete_maxheap() << " is deleted"<<endl;
			h.display();
			break;
		case 3:
			cout << (h.isEmpty() ? "Heap is Empty" : "Heap is not Empty") << endl;
			break;
		case 4:
			cout << (h.isFull() ? "Heap is Full" : "Heap is not Full") << endl;
			break;
		case 5:
			h.level();
			break;
		case 6:
			exit(1);
		default:
			cout << "Not regular cost, Please re-input the cost" << endl;
			break;
		}
	}
	return 0;
}