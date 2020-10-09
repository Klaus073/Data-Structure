#include<iostream>
#include<string>
using namespace std;

struct node{
    string data;
    node* next;
};

class List{
    private:
        node *head;
    public:
        List(){
            head = NULL;
        }
    
    node * get_new_node(string data){
        node* link_node = new node();
        link_node->data=data;
        link_node->next=NULL;
        return link_node;
    }

    void add_link_node_to_head(string data){
        if(head==NULL){
            head = get_new_node(data);
            return;
        }
        node* data_node = get_new_node(data);
        data_node->next = head;
        head = data_node;
    }

    void add_link_node_to_tail(string data){
        if(head==NULL){
            head = get_new_node(data);
           
            return;
        }
       
        node* data_node = get_new_node(data);
        node *tail = get_tail(head);
        tail->next = data_node;
       
    }

    node* get_head(){
        return head;
    }

    node* get_tail(node* head){
        node* tail_hunter =head;
        while(tail_hunter->next!=NULL)
        tail_hunter = tail_hunter->next;
        return tail_hunter;
    }

    // Task solution

    string get_data(node* random_node){
        if (random_node==NULL)
            return 0;
        else return random_node->data;
    }

    node* get_prev(node* random_node){
        node* temp_iter = head;
        if (random_node==NULL)
                return NULL;
        if (random_node==head)return head;
        while(temp_iter->next!=random_node){
            temp_iter=temp_iter->next;
        }
        return temp_iter;
    }        

    void print(){
        node* itera = head;
        while(itera){
            cout<<itera->data<<" ";
            itera = itera->next;
        }
    }
    void min_max()
    {
        // int max=6;
        // int min=2;
        int counter=0;
        int count[4];
        node* temp=head;
         while(temp!=NULL)
         {
             for (int i = 0; i < 5; i++)
             {
                    
                for (int i = 0; i < temp->data.length(); i++)
                {
                //cout<<"length of data"<<"("<<i<<")"<<" = "<<temp->data[i]<<endl;
                counter++;
             //  cout<<"=============="<< temp->data.size()<<endl;
               
                
                }
            //count
                 cout<<"length of strings "<<counter<<endl;
                 count[i] = counter;
               //  cout<<"---"<<count[i]<<endl;
             
             
                     temp = temp->next;
                    counter=0;
             }
             }
             int chk=count[0];
             int max=0;
             int min=0;
             for (int i = 0; i < 5; i++)
             {
                 if (max<=*(count+i))
                 {
                     max=chk;
                     
                    // cout<<"max ====="<<max<<endl;
                 }
                 if (max>=*(count+i))
                 {
                     min=chk;
                     
                 }
                 
                // cout<<"min ====="<<*(count+i)<<endl;
             }
             temp=head;
                  while (temp!=NULL)
             {
                 if(temp->data.size()==6)
                    {
                        cout<<temp->data<<endl;
                    }
                    if(temp->data.size()==2)
                    {
                        cout<<temp->data<<endl;
                    }
                    temp=temp->next;
             } 
       
    }
};

int main(){
    List l1;
    // "devops aiopss bell in is"
//// test ---1
    l1.add_link_node_to_tail("devops");
    l1.add_link_node_to_tail("aiopss");
    l1.add_link_node_to_tail("bell");
    l1.add_link_node_to_tail("in");
    l1.add_link_node_to_tail("is");
    l1.print();

    l1.min_max();
    //l1.print();
//// test ---2  
      l1.add_link_node_to_tail("bhaiya");
    l1.add_link_node_to_tail("abcder");
    l1.add_link_node_to_tail("msla");
    l1.add_link_node_to_tail("ha");
    l1.add_link_node_to_tail("ab");

    l1.print();
    l1.min_max();
}