#include "BinarySearchTree.h"

int main()
{
	BinaryTree b;
	b.setRoot(b.insertBSTree(b.getRoot(), 30));
	int temp = 0;

	while (true)
	{
		cout << "1. Insert 2. Delete 3. Search 4. Print 5. Quit" << endl;
		cout << "ют╥б> ";
		cin >> temp;

		switch (temp)
		{
		case 1:
			cout << "Enter number to insert: ";
			cin >> temp;
			b.insertBSTree(b.getRoot(), temp);
			break;
		case 2:
			if (b.getRoot() != NULL)
			{
				cout << "Enter number to delete: ";
				cin >> temp;
				b.deleteBSTree(b.getRoot(), temp);
				break;
			}
			else
			{
				cout << "Tree is empty" << endl;
				break;
			}
		case 3:
			if (b.getRoot() != NULL)
			{
				cout << "Enter number to search: ";
				cin >> temp;
				Node *tmp;
				tmp = b.searchBSTree(b.getRoot(), temp);
				if (tmp == NULL)
				{
					cout << "NOT found" << endl;
					break;
				}
				else
				{
					cout << tmp->data<<" is found" << endl;
					break;
				}
			}
			else
			{
				cout << "Tree is empty" << endl;
				break;
			}
		case 4:
			b.drawBSTree(b.getRoot(), 1);
			
			break;
		case 5:
			exit(1);
		}
	}

	return 0;
}