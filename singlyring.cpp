#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*last;
 
/*
 * Class Declaration
 */
class circular_llist
{
    public:
        void create_node(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_list();
        void update();
        void sort();
        circular_llist()
        {
            last = NULL;           
        }
};
 
void circular_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;   
    }
    else
    {
        temp->next = last->next; 
        last->next = temp;
        last = temp;
    }
}
 
/*
 * Insertion of element at beginning 
 */
void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    node *temp;
    temp = new node;
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}
 
/*
 * Insertion of element at a particular place 
 */
void circular_llist::add_after(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
   node *temp, *temp1;
    temp1 = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        temp1 = temp1->next;
        if (temp1 == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }
    temp = new node;
    temp->next = temp1->next;
    temp->info = value;
    temp1->next = temp;
    /*Element inserted at the end*/
    if (temp1 == last)
    { 
        last=temp;
    }
}
 
/*
 * Deletion of element from the list
 */
void circular_llist::delete_element(int value)
{
    node *temp, *temp1;
    temp1 = last->next;
      /* If List has only one element*/
    if (last->next == last && last->info == value)  
    {
        temp = last;
        last = NULL;
        delete temp;
        return;
    }
    if (temp1->info == value)  /*First Element Deletion*/
    {
        temp = temp1;
        last->next = temp1->next;
        delete temp;
        return;
    }
    while (temp1->next != last)
    {
        /*Deletion of Element in between*/
        if (temp1->next->info == value)    
        {
            temp = temp1->next;
            temp1->next = temp->next;
            delete temp;
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        temp1 = temp1->next;
    }
    /*Deletion of last element*/
    if (temp1->next->info == value)    
    {
        temp = temp1->next;
        temp1->next = last->next;
        delete temp;		
        last = temp1;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}
 
/*
 * Search element in the list 
 */
void circular_llist::search_element(int value)
{
     node *temp1;
    int counter = 0;
    temp1 = last->next;
    while (temp1 != last)
    {
        counter++;
        if (temp1->info == value)    
        {
            cout<<"Element "<<value; 
            cout<<" found at position "<<counter<<endl;
            return;
        }
        temp1 = temp1->next;
    }
    if (temp1->info == value)    
    {
        counter++;             
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}
 
/*
 * Display Circular Link List 
 */
void circular_llist::display_list()
{
     node *temp1;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return;
    }
    temp1 = last->next;
    cout<<"Circular Link List: "<<endl;
    while (temp1 != last)
    {
        cout<<temp1->info<<"->";
        temp1 = temp1->next;
    }
    cout<<temp1->info<<endl;
}
 
/*
 * Update Circular Link List 
 */
void circular_llist::update()
{
    int value, pos, i;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to update"<<endl;
        return;
    }
    cout<<"Enter the node position to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *temp1;
    temp1 = last->next;
    for (i = 0;i < pos - 1;i++)
    {
        if (temp1 == last)
        {
            cout<<"There are less than "<<pos<<" elements.";
            cout<<endl;
            return;
        }
        temp1 = temp1->next;
    }
    temp1->info = value;  
    cout<<"Node Updated"<<endl;
} 
 
/*
 * Sort Circular Link List 
 */
void circular_llist::sort()
{
   node *temp1, *ptr;
    int temp;
    if (last == NULL) 
    {
        cout<<"List is empty, nothing to sort"<<endl;
        return;
    }
    temp1 = last->next;
    while (temp1 != last)
    {
        ptr = temp1->next;
        while (ptr != last->next)
        {
            if (ptr != last->next)
            {
                if (temp1->info > ptr->info)
                {
                    temp = temp1->info;
                    temp1->info = ptr->info;
                    ptr->info = temp;
                }
            }
            else
            {
                break;
            }
            ptr = ptr->next;    
        }
        temp1 = temp1->next;         
    }
}

int main()
{
    int choice, element, position;
    circular_llist cl;
    while (1)
    {
        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"Circular singly linked list"<<endl;
        cout<<endl<<"---------------------------"<<endl;     
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at beginning"<<endl;
        cout<<"3.Add after"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Search"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Update"<<endl;
        cout<<"8.Sort"<<endl;
        cout<<"9.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cl.create_node(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cl.add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element after position: ";
            cin>>position;
            cl.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (last == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.delete_element(element);
            cout<<endl;
            break;
        case 5:
            if (last == NULL)
            {
                cout<<"List Empty!! Can't search"<<endl;
                break;
            }
            cout<<"Enter the element to be searched: ";
            cin>>element;
            cl.search_element(element);
            cout<<endl;
            break;
        case 6:
            cl.display_list();
            break;
        case 7:
            cl.update();
            break;
        case 8:
            cl.sort();
            break;                      
        case 9:
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
 
/*
 * Create Circular Link List
 */
