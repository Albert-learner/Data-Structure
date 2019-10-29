#include "SinglyLinkedList.h"

int main()
{
	List li;

	li.deleteNode(10);
	cout << "-------------------------------" << "\n";
	li.insertNode(10);
	li.insertNode(5);
	li.traverseList();
	cout << "-------------------------------" << "\n";
	li.insertNode(30);
	li.searchNode(5);
	cout << "-------------------------------" << "\n";

	li.deleteNode(5);
	li.traverseList();
	cout << "-------------------------------" << "\n";
	li.searchNode_pos(3);
	cout << "-------------------------------" << "\n";
	li.printLast();
	cout << "-------------------------------" << "\n";
	li.insertNode(40);
	li.invert();
	li.traverseList();
	return 0;
}