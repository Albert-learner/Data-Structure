#include "Stack.h"
#include "Queue.h"
#include "CircularQueue.h"

int main()
{
	Stack st;
	Queue qu;
	CQueue cq;

	cout << "1. "<<"\n";
	st.push('a');
	qu.enQueue('b');
	qu.enQueue('c');
	qu.enQueue('d');
	st.push('e');
	cout << "-------------------" << "\n";
	st.push('F');
	qu.enQueue('G');
	cout << "-------------------" << "\n";
	st.displayStack();
	cout << "-------------------" << "\n";
	qu.printQueue();
	cout << "-------------------" << "\n";
	cout << st.pop();
	cout << qu.deQueue();
	cout << qu.deQueue();
	cout << qu.deQueue();
	cout << st.pop()<<"\n";
	cout << "-------------------" << "\n";
	st.pop();
	qu.deQueue();
	cout << "-------------------" << "\n";
	cq.enQueue('A');
	cq.enQueue('B');
	cq.enQueue('C');
	cq.deQueue();
	cq.enQueue('D');
	cout << "-------------------" << "\n";
	cq.printQueue();
	cout << "\n";
	cq.deQueue();
	cq.deQueue();
	cq.deQueue();
	return 0;
}