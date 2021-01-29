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
    CBT(){
        node *left=NULL;
        node *right=NULL;
        root=NULL;
    }
    ~CBT();
    node* Get_Root() 
    {
		return root;
	}

int size(node* node)  
    {  
    if (node == NULL)  
       return 0;  
    else
      return(size(node->left) + 1 + size(node->right));  
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
    int height=0;
    if (root == NULL)
        {
			root = Create(data);
			return;
		}
        int height = maxDepth(temp->left);
        int expected_node = pow(2, height) - 1;
        int left_tree_node_count = size(temp->left);
        int right_tree_node_count = size(temp->right);
    // if (left_tree_node_count = right_tree_node_count)
    //     {
    //         CBTinsertion(temp->left);

    //     }
    // else if (expected_node != left_tree_node_count)
    //     if (temp->left==NULL)
    //     {
    //         //insert node here
    //         return    
    //     }
    //     else
    //     {
    //         CBTinsertion(temp->left);
    //     }
    //     else if(temp->right==NULL)
    //     {
    //         // insert code
    //         return 
    //     }
    if(left_tree_node_count==right_tree_node_count)
        {
            cout<<"count left and right equal"<<endl;
            CBTinsertion(temp->left,data);
        }
        else  if(expected_node != left_tree_node_count)
        {
            if(temp->left == NULL)
            {
                cout<<"temp left = null"<<endl;
                temp = Create(data);
                root=temp;
                return;
            }else
            {
                cout<<"temp left = null else part"<<endl;
                CBTinsertion(temp->left,data);
            }
        }
        else if(temp->right == NULL)
        {
            cout<<"temp right = null"<<endl;
            temp = Create(data);
            root=temp;
            return;
        }
        else if(expected_node != right_tree_node_count)
        {
            if(temp->right == NULL)
            {
                cout<<"temp right = null"<<endl;
                temp = Create(data);
                return;
            }
            else
            {
                cout<<"temp right = null part else"<<endl;
                CBTinsertion(temp->right,data);
            }
            
        }
        
        
}
 void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->val << " ";
		print(temp->right);
	}
    
};
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
    //cout<<"heihgt"<<CBT.find_height(CBT.Get_Root(),0)<<endl;

    cbt.CBTinsertion(cbt.Get_Root(), 10);
    cbt.CBTinsertion(cbt.Get_Root(), 11);
    // CBT.CBT_inseration(CBT.Get_Root(), 16);
    // CBT.CBT_inseration(CBT.Get_Root(), 5);
    // CBT.CBT_inseration(CBT.Get_Root(), 23);
    // CBT.CBT_inseration(CBT.Get_Root(), 17);
    // CBT.CBT_inseration(CBT.Get_Root(), 15);
    // CBT.CBT_inseration(CBT.Get_Root(), 33);
    cbt.print(cbt.Get_Root());
   
    return 0;
}
   