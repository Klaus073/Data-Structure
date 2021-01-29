#include <iostream>
using namespace std;
struct node
{

	int data;
	node* next;
};
class list
{
	node* head, * tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void Create_Node()
	{
		int value;
		cout << "elemnt inside the list \n";
		cin >> value;
		node* temp = new node;
		temp->data = value;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else

		{
			tail->next = temp;
			tail = tail->next;

		}

	}
	void Insert_in_the_start()
	{
		int x;
		cout << "Enter the element that you want to insert in the start \n";
		cin >> x;
		node* temp = new node;
		temp->data = x;
		temp->next = head;
		head = temp;
	}
	void Insert_in_the_end()
	{
		int x;
		cout << endl;
		cout << "Enter the element that you want to insert at the end \n";
		cin >> x;
		node* temp = new node;
		temp->data = x;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;

		}

	}
	void Insert_at_the_new_pos()
	{
		int pos;
		int x;
		cout << "Enter the position of your new node \n";
		cin >> pos;
		node* curr = new node;
		node* pre = new node;
		node* temp = new node;
		curr = head;
		for (int i = 1; i < pos; i++)
		{
			pre = curr;
			curr = curr->next;
		}
		cout << "Enter the data \n";
		cin >> x;
		temp->data = x;
		pre->next = temp;
		temp->next = curr;

	}

	void display()
	{
		node* temp = new node;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}

	void Delete_First_Node()
	{
		cout << "After deleting the first node of the list \n";
		node* temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}
	void Delete_End()
	{
		node* temp = new node;
		node* previous = new node;
		temp = head;
		while (temp->next != NULL)
		{
			previous = temp;
			temp = temp->next;

		}
		tail = previous;
		previous->next = NULL;
		delete temp;
	}

	void Delete_Position()
	{
		int position;
		cout << "Enter the position of the node you want to delete \n";
		cin >> position;
		node* temp = new node;
		node* previous = new node;
		temp = head;
		for (int i = 1; i < position; i++)
		{
			previous = temp;
			temp = temp->next;
			
		}
		previous->next = temp->next;
	}

	int Search()
	{
		int index = 0;
		int s;
		cout << "Enter the element you want to search \n";
		cin >> s;
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == s)
			{
				cout << "Element is found \t" << "at node \t" << index << endl;
				return index;
				break;
			}
			temp = temp->next;
			index++;
			



		}
		cout << "Not found \n";
		return -1;
	}
	void Size()
	{
		node* temp = head;
		int size = 0;
		while (temp != NULL)
		{
			temp=temp->next;
			size++;
		}
		cout << "Size of list is " << size << endl;
	}
	void Mid_Point()
	{
		
	}

    void reverse_list()
        {
                node* temp = head; 
                node *prev = NULL, *next = NULL; 
                while (temp != NULL)
                    {   
                        next = temp->next; 
            
                        // Reverse temp node's pointer 
                        temp->next = prev; 
            
                        // Move pointers one position ahead. 
                        prev = temp; 
                        temp = next; 
                    } 
                        head = prev; 
            }

    void swap_list_element()
    {
        node* temp,*tail,*test,*current=NULL;
        temp=tail=current=test=head;
        if (temp==NULL)
        {
            cout<<"list is empty"<<endl;
        }
        
        while (temp!=NULL)
        {
           // tail=head;
            if (temp->next==NULL)
            {
                temp=tail;
                current=temp->next;
                tail->next=test;
            }
            
            
        }
        temp=temp->next;
        

    }
        
};

int main()
{
	list a;
	a.Create_Node();
	a.Create_Node();
	a.Create_Node();
	a.Create_Node();
	a.Create_Node();
	cout << endl;
	cout << endl;
	a.display();
	cout << endl;
	cout << endl;
	a.Size();
	//a.Mid_Point();

    a.reverse_list();
    a.display();
    cout << endl;
	cout << endl;

    a.swap_list_element();
    a.display();
     cout << endl;
	cout << endl;
	return 0;
}