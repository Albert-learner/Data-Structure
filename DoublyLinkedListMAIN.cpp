#include "DoublyLinkedList.h"

int main()
{
	List list;
	list.insertList(3);
	list.insertList(5);
	list.insertList(1);

	list.backwardList();

	list.deleteList(1);
	list.deleteList(5);
	list.insertList(2);
	list.forwardList();

	cout << list.listLength() << "\n";
	list.searchList(3);
	
	return 0;
}