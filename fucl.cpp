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
       //node* Delete( node *root, int data);
       bool bst_search(node *temp,int key);
       int traverse_for_depth(node *temp);
       node* bst_max(node* temp);
       node* bst__2nd_max(node* temp);
       node* bst__3rd_max(node* temp);
       node* bst_min(node* temp);


        int size(node* node)  
            {  
                if (node == NULL)  
                    return 0;  
                else
                    return(size(node->left) + 1 + size(node->right));  
            }


      node* predesessor(node* temp)    
        {
            while(root->left != NULL) 
            root = root->left;
            return root;
        }

int maxDepth(node* temp)  
{  
    if (temp == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */

        int lDepth = maxDepth(temp->left);  
        int rDepth = maxDepth(temp->right);  
      
        /* use the larger one */
        if (temp->left!=NULL && temp->right==NULL)
        {
             if (lDepth > rDepth)
        {
        
        
            return(lDepth + 1);  
    }
        else
        {
         return(rDepth + 1);
        }  
        }
        
       
    }  
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

int bin_search_tree :: traverse_for_depth(node *temp)
{
    int count_left_depth=0;
    int count_right_depth=0;
   if(temp==NULL)
    {    cout<<" Tree is empty.\n";  
          return 0; 
    }
   if( temp->left!=NULL )
    		 traverse_for_depth(temp->left);
             count_left_depth++;
             return count_right_depth;
   if( temp->right!=NULL )
    		 traverse_for_depth(temp->right);
             count_right_depth++;
             return count_right_depth;
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

bool bin_search_tree :: bst_search(node *temp,int key)
{
bool flag=false;  
    if( temp==NULL )
    {
           return NULL;
    }
    else if (temp->info==key)
    {
        flag=true;
        return flag;
    }

    else if (key<temp->info)
    {
       return bst_search(temp->left,key);
    }
    else if (key>temp->info)
    {
       return bst_search(temp->right,key);
    }
    else
       return flag;

}

node* bst_min(node* temp)
    {
        if(temp == NULL)
            return NULL;
        else if(temp->left == NULL)
            return temp;
        else
            return bst_min(temp->left);
    }

    node* bst__2nd_max(node* temp)
    {
        if(temp == NULL)
            return NULL;
        else if(temp->right->right == NULL)
            return temp;
        else
            return bst_min(temp->right);
    }

    // node* bst__3rd_max(node* temp)
    // {
    //     if(temp == NULL)
    //         return NULL;
    //     else if(temp->right->right->right == NULL)
    //         return temp;
    //     else
    //         return bst_min(temp->right);
    // }



    node* bst_max(node* temp) {
        if(temp == NULL)
            return NULL;
        else if(temp->right == NULL)
            return temp;
        else
            return bst_max(temp->right);
    }

// void bin_search_tree :: print_in_order(node *temp)
// {
//    if(temp==NULL)
//     {    cout<<" Tree is empty.\n";  
//           return; 
//     }
//    if( temp->left!=NULL )
//     		 print_in_order(temp->left);
//              cout<<temp->info<<" ";
//    if( temp->right!=NULL )
//     		 print_in_order(temp->right);
// }



void bin_search_tree :: options()
{
 cout<<"\n\n ************** Select Option *****************.\n";
 cout<<"\n Enter any of choices.\n";
 cout<<"\n 1 : Adding (inserting) node in BST.\n";
 cout<<"\n 2 : Print the whole BST .\n";
 cout<<"\n 3 : searching in BST.\n";
 cout<<"\n 4 : height of bst .\n";
 cout<<"\n 5 : size of bst .\n";
}
int main()
{
  //clrscr();
  int key=0;
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
        
        cout<<"enter key to find"<<endl;
        cin>>key;
		cout<<obj.bst_search(obj.root,key);
        if (obj.bst_search(obj.root,key)==true)
        {
            cout<<"found"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
        
		break;
       case '4':
		cout<<obj.maxDepth(obj.root);
		break;
        case '5':
		//clrscr();
		cout<<obj.size(obj.root);
		break;
       default :
		exit(0);
		break;
     } // end of switch.
  }
  return 0; // end of while.
}//-----------------------------------------------


//--------------------------------------------------------
