#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

class BST
{
public:
	node* root;
	node* temp;
	node* temp1;
	int l2;
	int l3;
	int s2;
	int s3;

	BST()
	{
		root = temp = temp1 = NULL;

	}
    node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}
    void input(node* temp,int data)
    {
       
        if(temp ==NULL)
        {
             temp = Create(data);
             return;
        }
       
        int height_l = height(temp->left);
        int excepted_node = pow(2,height_l)-1;
        int left_tree_node_count  = count_nodes(temp->left);
        int right_tree_node_count = count_nodes(temp->right);

        if(left_tree_node_count==right_tree_node_count)
        {
			 if (temp->left==NULL)
        {
             temp->left = Create(data);
             return;
        }
			
            else input(temp->left,data);
        }
        
       
	else	if(excepted_node != left_tree_node_count)
        {
            if(temp->left == NULL)
            {
                 temp->left = Create(data);
             return;
            }
			
			else
            {
                 input(temp->left,data);
            }
        }
       else if(temp->right == NULL)
        {
           
            temp->right = Create(data);
            
            return;
        }
        
            else
            {
                
               input(temp->right,data);
            }
      
    
       
    }

	// void input(node* temp, int data)
	// {
		
	// 	if (root == NULL)
	// 	{
	// 		root = Create(data);
	// 		return;
	// 	}
	// 	//int totalHeight= height(temp);
    //     int LeftHeight= height(temp->left);
    //     int expNode = pow(2,LeftHeight)-1;
    //     int LtreeCount= count_nodes(temp->left);
    //     int Rtreecount= count_nodes(temp->right);
    //     //int totCount=count_nodes(root,0);

    //     if (LtreeCount==Rtreecount)
    //     {
            
    //         if(temp->left==NULL ) 
    //        {  
    //               temp->left = Create(data);
	// 		return;
    //        }
    //        else input(temp->left,data);
           
    //     }
	// 	else if (expNode!=LtreeCount)
    //     {
    //         if (temp->left==NULL)
    //         {
    //              temp->left = Create(data);
    //                 return ;
    //         }
    //         else
    //         {
    //             input(temp->left,data);
    //         }
            
    //     }
    //    else if (temp->right==NULL)
    //     {
    //        temp->right = Create(data);
    //        return;
    //     }
    //     else
    //     {
    //         input(temp->right,data);
    //     }
        

      

    // //   if (expNode!=Rtreecount)
    // //   {
          
    // //       temp->right=new node;
    // //       temp->right->data=data;
    // //      temp->right->left=NULL;
    // //       temp->right->right=NULL;
    // //       return;

    // //   }


	// }

	 void print(node *temp) {
		if (temp == NULL)
			return;

          
		print(temp->left);
		cout << temp->data << " ";  
		print(temp->right);
	}

	void search(node*temp,int number)
	{
		if (temp==NULL)
		{
			cout<<"Number not present"<<endl;
			return;
		}
		if (number==temp->data)
		{
			cout<<"Number "<<number<< " Exists"<<endl;
			
			return;
		}
		
		
		if (number>temp->data)
		{
			search(temp->right,number);
			return;
			
		
		}
		if (number<temp->data)
		{
			search(temp->left,number);
			return;
			
		}
	}


	
    int height (node* temp)

{
	if (temp==NULL)
	{
		return -1;
	}
	int ldepth= height(temp->left);
	int rdepth=height (temp->right);

	if (ldepth>rdepth)
	{
		return (ldepth+1);

	}
	else {
		return rdepth+1;
    }
	
	
}



    int count_nodes(node* node)  
    {  
    if (node == NULL)  
       return 0;  
    else
      return(1+count_nodes(node->left) + count_nodes(node->right));  
    }
	
};

int main()
{
	int data;
	BST A;

	int count1=0;
	int count2=0;
	A.input(A.root, 10);
	A.input(A.root, 11); 
	A.input(A.root, 16);
	
	A.input(A.root, 5);
	A.input(A.root, 23);
	A.input(A.root, 17);
	A.input(A.root, 15);
	A.input(A.root, 33);
	// A.input(A.root, 9);
	// A.input(A.root, 10);
	

	//A.input(A.root, 11);
	A.print(A.root);
	cout<<endl;
	
	
//	cout<< A.height(A.root);

	//cout<<endl;
    //cout<<"HEHEHEHE"<<A.count_nodes(A.root,0);
}
//8492105111637