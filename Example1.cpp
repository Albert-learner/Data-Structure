#include "Stack.h"
#include "Queue.h"
#include "CircularQueue.h"

int main()
{
	Stack st;
	Queue qu;
	CQueue cq;

	st.push('a');
	qu.enQueue('b');
	qu.enQueue('c');
	qu.enQueue('d');
	st.push('e');
	st.push('a');
	qu.enQueue('a');
	cout << "-----------------------" << "\n";
	st.displayStack();
	qu.printQueue();
	cout << "-----------------------" << "\n";
	cout << st.pop();
	cout << qu.deQueue();
	cout << qu.deQueue();
	cout << qu.deQueue();
	cout << st.pop();
	cout << "\n";
	cout << "-----------------------" << "\n";
	st.pop();
	qu.deQueue();
	cout << "-----------------------" << "\n";
	cq.enQueue('a');
	cq.enQueue('b');
	cq.enQueue('c');
	cq.deQueue();
	cq.enQueue('a');
	cout << "-----------------------" << "\n";
	cq.printQueue();
	return 0;
}