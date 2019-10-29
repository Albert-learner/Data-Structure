#include "linkedStackQueue.h"

int main()
{
	linkedStack ls;
	linkedStack ls1;
	Node *p;
	linkedQueue lq;

	ls.push('a');
	ls.push('e');
	ls.displayStack();
	cout << "------------------------------" << "\n";
	lq.enQueue('b');
	lq.enQueue('c');
	lq.enQueue('d');
	lq.displayQueue();
	cout << "------------------------------" << "\n";
	p = ls.invertStack(ls.getHead());
	
	return 0;
}