#include "BinarySearchTree.h"

int main()
{
	BST bst;
	bst.setRoot(bst.insertBST(bst.getRoot(), 30));
	int choice = 0;

	while (1)
	{
		cout << "(1. Insert 2. Delete 3. Search 4. Print 5. Traverse 6. Leaf 7. quit)" << endl;
		cout << "ют╥б > ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter number to insert : ";
			cin >> choice;
			bst.insertBST(bst.getRoot(), choice);
			break;
		case 2:
			if (bst.getRoot() != NULL)
			{
				cout << "Enter number to delete : ";
				cin >> choice;
				bst.deleteBST(bst.getRoot(), choice);
			}
			else
			{
				cout << "Tree is Empty" << endl;
			}
			break;
		case 3:
			if (bst.getRoot() != NULL)
			{
				cout << "Enter number to search : ";
				cin >> choice;
				Node *tmp;
				tmp = bst.searchBST(bst.getRoot(), choice);
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
			bst.drawBST(bst.getRoot(), 1);
			break;
		case 5:
			bst.traverse();
			break;
		case 6:
			bst.leaf();
			break;
		case 7:
			cout << "Program End" << endl;
			break;
		default:
			cout << "Input Error, you should re-input the choice" << endl;
		}
	}
	return 0;
}