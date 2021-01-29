#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
class link
{
private:
	node* head, * tail, * temp, * temp1;//pointers
	int key;
public:
	link()
	{
		head = temp = temp1 = NULL;
		tail = NULL;
		//newnode = NULL;
		//info = NULL;
	}
	void add()
	{
		if (head == NULL)
		{
			head = new node;
			cout << "enter the value for 1st node" << endl;
			cin >> head->data;
			head->next = NULL;
			return;
		}
		else
		{
			temp = head;
			cout << "enter the value you want to add next node" << endl;
			cin >> key;
			while (temp != NULL)
			{
				if (temp->data == key)
				{
					//node*temp=new node
					temp1 = new node;
					cout << "enter the value for new node" << endl;
					cin >> temp1->data;
					temp1->next = temp->next;
					temp->next = temp1;

				}
				temp = temp->next;
			}

		}
	}
	void del()
	{
		if (head == NULL)
		{
			cout << "cant delete any" << endl;
			return;
		}
		else
		{
			cout << "enter the value you want to delete" << endl;
			cin >> key;
			temp = head;
			while (temp != NULL)
			{
				if (temp->next->data == key)
				{
					//cout << "werwer" << endl;
					//temp1 = new node;
					temp1 = temp->next;
					temp->next = temp1->next;
					//temp1->next = temp;//we can use temp->next->next too
					delete temp1;
					break;
				}
				temp = temp->next;
			}

		}
	}

	void print()
	{
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data;
			temp = temp->next;

		}
		if (head == NULL)
		{
			cout << "empty" << endl;

		}
	}
	
	~link()
	{
		delete head;
	}





};
int main()
{
	link a;
	a.add();
	a.add();
	a.add();
	a.del();
	a.print();

	system("pause");
	return 0;

}