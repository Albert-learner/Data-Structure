#include "LAB5_queue.h"

int main()
{
	int data[10] = { 16, 7, 10, 4, 5, 2, 9, 1, 3, 8 };
	Queue queue;

	for (int i = 0; i < 10; i++)
	{
		queue.enQueue(data[i]);
	}

	queue.printQueue();
	cout << "\n";

	for (int i = 0; i < 10; i++)
	{
		cout << queue.deQueue() << ' ';
	}
	cout << "\n";

	return 0;
}