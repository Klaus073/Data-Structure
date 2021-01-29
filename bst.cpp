#include <iostream>


using namespace std;
struct node
{
  int info;
  node *left,*right;
};
class bin_search_tree
{
private :
	    node *temp,*temp1;
   public  :
	    node *root;
	    int number;
	    bin_search_tree();  //constructor
	    void options();
	    void insert_bst_search_tree(node *); //insertion
	    void print_in_order(node *);    //printing
       node* Delete( node *root, int data);


      node* FindMin(node* temp)
        {
            while(root->left != NULL) 
            root = root->left;
            return root;
        }
};
bin_search_tree :: bin_search_tree()
{
  root=temp=NULL;
}
void bin_search_tree :: print_in_order(node *temp)
{
   if(temp==NULL)
    {    cout<<" Tree is empty.\n";  
          return; 
    }
   if( temp->left!=NULL )
    		 print_in_order(temp->left);
             cout<<temp->info<<" ";
   if( temp->right!=NULL )
    		 print_in_order(temp->right);
}

void bin_search_tree :: insert_bst_search_tree(node *temp)
{
    if( root==NULL )
    {
        temp=new node;
        temp->info = number;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return;
    }

    if( temp->info==number )
    {
        cout<<" \n Given number is already present in tree.\n";
        return;
    }

    if(temp->info > number)
    {
      if( temp->left!=NULL )
        {
            insert_bst_search_tree(temp->left);
            return;
        }
      else
        {
            temp->left=new node;
            temp->left->info = number;
            temp->left->left=NULL;
            temp->left->right=NULL;
            return;
        }
   }
   if(temp->info < number)
   {
      if( temp->right!=NULL )
       {
            insert_bst_search_tree( temp->right );
            return;
       }

      else
       {
            temp->right=new node;
            temp->right->info = number;
            temp->right->left=NULL;
            temp->right->right=NULL;
            return;
       }
   }

}


node* bin_search_tree :: Delete(node *temp, int data) {
	if(temp == NULL) {
        cout<<"nothing to delete"<<endl;
        return temp; 
    }
    else if(data < temp->info) 
       temp->left =Delete(temp->left,data);
	else if (data > temp->info) 
        temp->right =  Delete(temp->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(temp->left == NULL && temp->right == NULL) { 
			delete temp;
			temp = NULL;
		}
		//Case 2: One child 
		else if(temp->left == NULL) { 
			node *temp1 = temp;
			temp = temp->right;
			delete temp1;
		}
		else if(temp->right == NULL) {
			node *temp1 = temp;
			temp = temp->left;
			delete temp1;
		}
		// case 3: 2 children
		else { 
			node *temp1 = FindMin(temp->right);
			temp->info = temp1->info;
			temp->right =  Delete(temp->right,temp1->info);
		}
	}
    return temp;
}

void bin_search_tree :: options()
{
 cout<<"\n\n ************** Select Option *****************.\n";
 cout<<"\n Enter any of choices.\n";
 cout<<"\n 1 : Adding (inserting) node in BST.\n";
 cout<<"\n 2 : Print the whole BST .\n";
 cout<<"\n 3 : Delete in BST.\n";
  cout<<"\n 4 : Quitting the Program.\n";
}
int main()
{
  //clrscr();
  int data=0;
  char ch;
  bin_search_tree obj;
  while( 4 )
  {
    obj.options();
   cin>>ch;
    switch(ch)
     {
       case '1':
	//	clrscr();
		cout<<"\n Enter number to add in a tree... \n";
		cin>>obj.number;
		obj.insert_bst_search_tree( obj.root );
		break;
        case '2':
		//clrscr();
		obj.print_in_order(obj.root);
		break;
        case '3':
        cout<<"enter data to delete"<<endl;
        cin>>data;
		obj.Delete(obj.root,data);
		break;
       case '4':
		exit(0);
		break;
       default :
		exit(0);
		break;
     } // end of switch.
  }
  return 0; // end of while.
}//-----------------------------------------------


//--------------------------------------------------------
