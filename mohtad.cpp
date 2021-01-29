#include<iostream>
#include<cmath>

using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
};
class CBT
{
private:
    node *root;
public:
    CBT(){      //constructor
        node *left=NULL;
        node *right=NULL;
        root=NULL;
    }
    
    node* Get_Root() 
    {
		return root;
	}

int size(node* node)  
    {  
    if (node == NULL)  
       return 0;  
    else
      return(1+size(node->left) + size(node->right));  
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

node* Create(int data) {
		node *Node = new node();
		Node->val = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

void CBTinsertion(node *temp,int data)
{
   
    if (root == NULL)
        {
			root = Create(data);
			return;
		}
        int height = maxDepth(temp->left);  // it will pass the node to height function and ll calculate height
            int expected_node = pow(2, height) - 1; // 
            int left_tree_node_count = size(temp->left);
        int right_tree_node_count = size(temp->right);
   
    if(left_tree_node_count==right_tree_node_count)
    {
        if (temp->left==NULL)
        {
             temp->left = Create(data);
             return;
        }
        
           else  CBTinsertion(temp->left,data);
        }
    else  if(expected_node != left_tree_node_count)
        {
            if(temp->left == NULL)
            {
                cout<<"temp left = null"<<endl;
                temp->left = Create(data);
              
                return;
            }else 
            {
                
                CBTinsertion(temp->left,data);
            }
        }
        else if(temp->right == NULL)
        {
           
            temp->right = Create(data);
            //root=temp;
            return;
        }
        
            else
            {
                
                CBTinsertion(temp->right,data);
            }
            
        
        
        
}
 void print(node *temp) {
		if (temp == NULL)
			return;

         cout << temp->val << " ";   
		print(temp->left);
		
		print(temp->right);
	}
    
};
//      sir's sudo code
// CBTinsertion(node *temp)
// root is null then directly insert
// height = find_height(temp->left)
// int expected_node = pow(2, height) - 1
// int left_tree_node_count = count_node(temp-left)
// int right_tree_node_count = count_node(temp->right)

// if left_tree_node_count == right_tree_node_count
//     then CBTinsertion(temp->left)

// else if expected_node != left_tree_node_count:
//     if (temp->left==NULL)
//     insert node here
//     return

//     else CBTinsertion(temp->left)

//     else if temp->right==NULL
//     insert node here
//     returnt

//     else if expected_node != left_tree_node_count:
//         if (temp->left==NULL)
//         insert node here
//         return

// else CBTinsertion(temp->right)


int main()
{
    CBT cbt;
   

    cbt.CBTinsertion(cbt.Get_Root(), 10);
    cbt.CBTinsertion(cbt.Get_Root(), 11);
     cbt.CBTinsertion(cbt.Get_Root(), 16);
    cbt.CBTinsertion(cbt.Get_Root(), 5);
     cbt.CBTinsertion(cbt.Get_Root(), 23);
    cbt.CBTinsertion(cbt.Get_Root(), 17);
     cbt.CBTinsertion(cbt.Get_Root(), 15);
    cbt.CBTinsertion(cbt.Get_Root(), 33);

    
    cbt.print(cbt.Get_Root());
   
    return 0;
}
   