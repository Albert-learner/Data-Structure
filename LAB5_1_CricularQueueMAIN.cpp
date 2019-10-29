#include "LAB5_1_CircularQueue.h"

int main()
{
	int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	CQueue cq;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cq.enQueue(data[i]);
	}
	cq.printCQueue();

	cout<<cq.deQueue()<<"\n";
	cout << cq.deQueue() << "\n";

	cq.enQueue(14);
	cq.printCQueue();
	return 0;
}