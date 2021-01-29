#include<iostream>
#include<string>
using namespace std;
struct node
{
    int info;
    struct node *next;
};

class Character_link_list
{
private:
  node* head;
public:
    Character_link_list()
    {
        head=NULL;
    }

void char_add()
{
    char data;
    if (head==NULL)
    {
        head=new node;
        cin>>data;
        head->info=data;
        head->next=NULL;
        return;
    }
    
}
   
};

