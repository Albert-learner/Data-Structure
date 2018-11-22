#include "MINHEAP.h"
using namespace std;

int main()
{
	MinHeap h;
	int temp = 0;
	cout << "<< Program Initiation >>" << endl;
	h.insert_minheap(8);
	h.insert_minheap(6);
	h.insert_minheap(4);
	h.insert_minheap(2);
	h.insert_minheap(5);
	h.insert_minheap(3);

	cout << "Now Heap: ";
	h.display();
	while (temp != 5)
	{
		cout << "1. insert_minheap 2. delete_minheap 3. isEmpty 4. isFull 5. Quit" << endl;
		cout << "ют╥б> ";
		cin >> temp;

		switch (temp)
		{
		case 1:
			cout << "insert> ";
			cin >> temp;
			h.insert_minheap(temp);
			break;
		case 2:
			cout << h.delete_minheap() << "is deleted";
			break;
		case 3:
			cout << (h.isEmpty() ? "Heap is Empty" : "Heap is not Empty") << endl;
			break;
		case 4:
			cout << (h.isFull() ? "Heap is Full" : "Heap is not Full") << endl;
			break;
		case 5:
			break;
		default:
			cout << "Not regular cost, Please re-input the cost" << endl;
			break;
		}
	}
	h.display();
	cout << endl;
	return 0;
}