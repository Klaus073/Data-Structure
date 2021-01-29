#include<iostream>

using namespace std;

struct node
{
    int data;
    node* next;
  //  node * previous;
};
class sRing
{
private:
    node *head, *temp, *temp1;
public:
int key=0;
    sRing(/* args */)
    {
        head = temp = temp1 = NULL;
    }
    
    void add()
    {
        int dat=0;
        if (head==NULL)
        {
            head=new node;
            cout<<"enter data at head"<<endl;
           cin>>dat;
           head->data=dat;
          //  head->data = data;
            head->next=head;
            return;

        }

        temp=head;
        cout<<"key???????? "<<endl;
        cin>>key;
        while (temp!=head)
        {
            if (temp->data==key)
            {
                temp1=new node;
                cout<<"enter data??????? "<<endl;
                cin>>temp1->data;
                temp1->next=temp->next;
                temp->next=temp1;
                return;
            }
            temp=temp->next;
            
        }
        
        
    }

    void print ()
    {
        temp=head;
        if (temp==NULL)
        {
            cout<<"list is empty "<<endl;
        }
        
        while (temp!=head)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        
    }
};

int main()
{
    int input=0;
    sRing obj;
    
    for (;;)
    {
       cout<<"1: add "<<endl;
       cout<<"2: print "<<endl;
       cout<<"3: exit "<<endl;
       cin>>input;
        if (input==1)
         {
           obj.add();
         }

        if (input==2)
         {
        obj.print();
         }
        if (input==3)
         {
          break;
         }
     
       return 0;
       
    }
    
    
}
