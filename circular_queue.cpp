#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class queue
{
	node* front;
	node* rear;
	node* temp;
	int counter=0;

public:
	queue()
	{
		front = rear = temp = NULL;
		//n = 5;
	}

	void enqueue()
	{
		if (front == NULL && rear == NULL)
		{
			cout << "Queue is Empty" << endl;

			rear = new node;
			cout << "Enter value of first element :";
			cin >> rear->data;
			front = rear;
			rear->next = front;
            counter++;
			
		}

		else
		{
			temp = new node;
			cout << "Enter value of element:";
			cin >> temp->data;
			rear->next = temp;
			temp->next = front;
			rear = temp;
			rear->next = temp->next;
            counter++;


		}
	}
	void display()
	{
		temp = front;
		if ((front == NULL) && (rear == NULL)) {
			cout << "Queue is empty" << endl;
			return;
		}
		cout << "Queue elements are: ";
		do {
			cout << temp->data << " ";
			temp = temp->next;
		}while (temp != front);
		cout << endl;
	}

	void dequeue()
	{
		if (front == NULL) {
			cout << "Underflow" << endl;
			return;
		}
		else if (front == rear)
		{
			temp = front;


			delete temp;

			temp = front = rear = NULL;
            counter--;
		}
		else {
			temp = front;
			front = front->next;
			rear->next = front;
			delete temp;
			temp = NULL;
            counter--;
		}
	}
};

int main()
{
	queue A;
	A.enqueue();
	A.enqueue();
	A.enqueue();
	A.display();
	A.dequeue();
	A.dequeue();
	A.dequeue();
	A.dequeue();
	A.display();
}