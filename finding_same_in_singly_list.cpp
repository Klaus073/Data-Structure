#include <iostream>
using namespace std;
struct node
{

	int data;
	node* next;
};
class list
{
	node* head, *temp,*temp1,* tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
        temp=NULL;
        temp1=NULL;
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
		node* current = new node;
		node* previous = new node;
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;

		}
		tail = previous;
		previous->next = NULL;
		delete current;
	}

	void Delete_Position()
	{
		int position;
		cout << "Enter the position of the node you want to delete \n";
		cin >> position;
		node* current = new node;
		node* previous = new node;
		current = head;
		for (int i = 1; i < position; i++)
		{
			previous = current;
			current = current->next;
			
		}
		previous->next = current->next;
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
	void repeated_elements()
	{
        int repeat_counter=0;
        temp=temp1=head;
		for (temp =head ; temp !=NULL; temp=temp->next)
        { //temp=head;
            for (temp1=head; temp1!=NULL;temp1=temp1->next )
            {
                if (temp->data==temp1->next->data)
                {
                    repeat_counter++;
                    cout<<"element "<<temp->data<<" repeated "<<repeat_counter<<" times"<<endl;
                    //repeat_counter=0;
                    if (temp1->next==NULL)
                    {
                        temp1=head;
                    }
                    
                    
                    
                    //return;
                }
               // repeat_counter=0;
            }
            
        }
        
        
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
    a.repeated_elements();
    cout << endl;
	cout << endl;
    
	return 0;
}