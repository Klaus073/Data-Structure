#include<iostream>
#include <math.h>
using namespace std;
 
struct node {
    int data;
    node *left, *right;
};
class CBT
{
 	node* temp;
    int height_tree;
 	public:
 		node* root;
    CBT()
    {
        height_tree=0;
    	root=temp=NULL;
	}
    node* Get_Root() 
    {
		return root;
	}


    node* newNode(int key)
    {
        node* temp1 = new node;
        temp1->data = key;
        temp1->left = temp1->right = NULL;
 
        return temp1;
    }

   int heighs(node* iter)
    {
        if (iter==NULL)
        {
            return 0;
        }
        //int lefts,rights;
        int left_s=heighs(iter->left)+1;
        int right_s=heighs(iter->right)+1;
        if(left_s>right_s)
        {
            return left_s;
        }
        else
        {
            return right_s;
        }
        
    }
	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}


    int count_node(node* root)
    {
        if(root==NULL)
        {
            return 0;
        }
         return(count_node(root->left) + 1 + count_node(root->right));  
         
    }

    void CBT_inseration(node* temp,int data)
    {
       
        if(temp ==NULL)
        {
             temp = Create(data);
             return;
        }
       
        int height = heighs(temp->left);
        int excepted_node = pow(2,height)-1;
        int left_tree_node_count  = count_node(temp->left);
        int right_tree_node_count = count_node(temp->right);

        if(left_tree_node_count==right_tree_node_count)
        {
			 if (temp->left==NULL)
        {
             temp->left = Create(data);
             return;
        }
			
            else CBT_inseration(temp->left,data);
        }
        
        //out<<"excepted node"<<excepted_node<<endl;cout<<"left node "<<endl;*/
	else	if(excepted_node != left_tree_node_count)
        {
            if(temp->left == NULL)
            {
                 temp->left = Create(data);
             return;
            }
			
			else
            {
                 CBT_inseration(temp->left,data);
            }
        }
       else if(temp->right == NULL)
        {
           
            temp->right = Create(data);
            
            return;
        }
        
            else
            {
                
               CBT_inseration(temp->right,data);
            }
      
    
       
    }

    void inorder(node* root)
    {
        if(root==NULL)
        {
            return;
        }

       cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
        
    }
};
int main()
{
    CBT cbt;
    cbt.CBT_inseration(cbt.Get_Root(), 10);
    cbt.CBT_inseration(cbt.Get_Root(), 11);
    cbt.CBT_inseration(cbt.Get_Root(), 16);
    cbt.CBT_inseration(cbt.Get_Root(), 5);
   cbt.CBT_inseration(cbt.Get_Root(), 23);
    cbt.CBT_inseration(cbt.Get_Root(), 17);
    cbt.CBT_inseration(cbt.Get_Root(), 15);
    cbt.CBT_inseration(cbt.Get_Root(), 33);
    cbt.inorder(cbt.Get_Root());
    return 0;
}