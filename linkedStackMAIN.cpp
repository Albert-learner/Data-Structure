#include "linkedStack.h"

int main()
{
	linkedStack ls;

	ls.push(30);
	ls.push(20);
	ls.push(50);
	ls.push(40);
	ls.push(100);

	ls.displayStack();

	ls.invert();
	ls.displayStack();
	ls.searchStack(20);
	return 0;
}