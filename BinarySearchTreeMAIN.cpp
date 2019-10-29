#include "BinarySearchTree.h"

int main()
{
	BST b;
	b.setRoot(b.insertBST(b.getRoot(), 30));
	int temp = 0;

	while (1)
	{
		cout << "1. Insert 2. Delete 3. Search 4. Print 5. Quit" << endl;
		cout << "ют╥б > ";
		cin >> temp;

		switch (temp)
		{
		case 1:
			cout << "Enter number to insert : ";
			cin >> temp;
			b.insertBST(b.getRoot(), temp);
			break;
		case 2:
			if (b.getRoot() != NULL)
			{
				cout << "Enter number to delete : ";
				cin >> temp;
				b.deleteBST(b.getRoot(), temp);
			}
			else
			{
				cout << "Tree is Empty" << endl;
			}
			break;
		case 3:
			if (b.getRoot() != NULL)
			{
				cout << "Enter number to search : ";
				cin >> temp;
				Node *tmp;
				tmp = b.searchBST(b.getRoot(), temp);
				if (tmp == NULL)
				{
					cout << "Not Found" << endl;
				}
				else
				{
					cout << tmp->data << " is found" << endl;
				}
			}
			else
			{
				cout << "Tree is Empty" << endl;
			}
			break;
		case 4:
			b.drawBST(b.getRoot(), 1);
			break;
		case 5:
			exit(1);
		default:
			cout << "Not regular cost, Please re-input the cost" << "\n";
			break;
		}
	}
	return 0;
}