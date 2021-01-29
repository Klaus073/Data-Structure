#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;

};
class bruh {
private:
    node* top;
    node* temp;
public:
    bruh() {

        top = NULL;
        temp = NULL;
    }
    void push(int x) {
        node* new_data = new node;
        new_data->data = x;
        new_data->next = top;
        top = new_data;
    }

    void pop() {
         temp=top;
        if (top == NULL) {
            cout << "the stack is underflows" << endl;
        }
        else

        {
          temp=top;
           
           top=top->next;
           temp->next =NULL;
            free(temp);
            cout<<"top data "<<top->data;
        }
        

    }
   /* void print() {
        struct node* ptr;
        if (top == NULL) {

            cout << "the stack underflows" << endl;

        }
        else
        {
            ptr = top;
            cout << "the displayed elememts of the stack will be" << endl;
            while (ptr != NULL) {
                cout << ptr->data;
                ptr = ptr->next;
            }
        }
    }
    */

};
int main() {
    bruh obj1;

    int choice = 0;
    for (;;) {
        cout << "enter your choice" << endl;
        cout << "1 for push" << endl;
        cout << "2 for pop" << endl;
        //cout << "3 for display" << endl;
        cout << "4 for exit" << endl;
        cin >> choice;
        if (choice == 1) {
            obj1.push(1);
            

        }
        if (choice == 2) {

            obj1.pop();

        }
        if (choice == 3) {

         //   obj1.print();


        }
        if (choice == 4) {

            break;

        }

    }



}