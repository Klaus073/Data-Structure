#include<iostream>
#include<climits>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

class BST {

private:
	node *root;

public:
    BST() {
		root = NULL;
		
	}

	bool check_left(node *temp) {
		if (temp->left == NULL) {
			return true;
		}
		else return false;
	}

    node*  bst_search(node *temp,int key)
{
//bool flag=false;  
    if( temp==NULL )
    {
           return NULL;
    }
    else if (temp->data==key)
    {
       // flag=true;
        return temp;
    }

    else if (key<temp->data)
    {
       return bst_search(temp->left,key);
    }
    else if (key>temp->data)
    {
       return bst_search(temp->right,key);
    }
    else
       return temp;

}

	bool check_right(node *temp) {
		if (temp->right == NULL)
			return true;
		else return false;
	}

	bool is_greater(int val, int val_1) {
		if (val > val_1)
			return true;
		else return false;
	}

	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	void Insertion(node *temp, int data) {
		if (root == NULL) {
			root = Create(data);
			return;
		}
		if (is_greater(temp->data, data)) {
			if (check_left(temp)) {
				temp->left = Create(data);
				return;
			}
			else Insertion(temp->left, data);

		}
		else {
			if (check_right(temp)) {
				
				temp->right = Create(data);
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else Insertion(temp->right, data);
		}

	}

	node *Get_Root() {
		return root;
	}

	void print(node *temp) {
		if (temp == NULL)
			return;

            
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}

    int size(node* node)  
            {  
                if (node == NULL)  
                    return 0;  
                else
                    return(size(node->left) + 1 + size(node->right));  
            }

           
  
    // ***************Part A*******************
    int count_nodes(node* iter, int val, int count=0)
    {
        if (iter==NULL)
        {
            return count;
        }
       return size(bst_search(iter,val));
        
        
    }

    ////Helper - of - part - B   ////////


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
 
 
    // ****************Part-B********************
    int left_most_node(node *root_iter){
        if (root_iter==NULL)
        {
            return 0;
        }
        node* temp1=root_iter->right;
        node* temp2=root_iter->left;

        if (maxDepth(temp1)>maxDepth(temp2))
        {
            return maxDepth(temp1);
        }
        else
            return maxDepth(temp2);
    }

 ////Helper - of - part - C   ////////
void right_leaves_helper(node* root, int& sum)
{
    if (root==NULL)
        return;
    
    
    if (root->right!=NULL && root->right->left==NULL && root->right->right==NULL)  //if it has right child and the child is leaf node 
        sum += root->right->data;   //then add the child value

    right_leaves_helper(root->left, sum);
    right_leaves_helper(root->right, sum);
}
     
    // **********************PART-C********************
    int right_leaves(node* root_iter){
        int sum=0;
       // right_leaves_helper(root_iter,sum);
       if (root_iter==NULL)
        return sum;
    //if it has right child and the child is leaf node 
    //then add the child value
    if (root_iter->right!=NULL && root_iter->right->left==NULL && root_iter->right->right==NULL)
        sum += root->right->data;

    right_leaves_helper(root->left, sum);
    right_leaves_helper(root->right, sum);
    return sum;
    }

 ////Helper - of - part - C   ////////

    int* AddToArray(node *root, int arr[],int& c)
{
     //int c=0;
    if(root == NULL) return 0;

 arr[c++] = root->data;
    AddToArray(root->left, arr,c);
    
    AddToArray(root->right, arr,c);


                return arr;
     
}
       
   
    // *********************PART-D******************
    int min_diff(node* root_iter, int diff = 0) {
		// YOUR CODE HERE
		int dif1 = INT_MAX;
		int dif2 = INT_MAX;

        dif1 = root_iter->data - root_iter->left->data;
        dif2 = root_iter->right->data - root_iter->data;

            if (root_iter == NULL)
			return diff;

        //     if (root_iter->left != NULL)
		// 	 diff==dif1;
		// else if (root_iter->right != NULL)
		// 	  diff==dif2;
        else
        {
             min_diff(root_iter->left, diff);
		     min_diff(root_iter->right, diff);
		
		
		if (dif1 < dif2)
        {
			diff = dif1;
                return diff;
            }
	else
    {
			diff = dif2;
            return diff;
            }
        }
        

        
            //return diff;
		
	}
       


};

int main() {
	BST bst;
	bst.Insertion(bst.Get_Root(), 20);
    bst.Insertion(bst.Get_Root(), 15);
     bst.Insertion(bst.Get_Root(), 25);
     bst.Insertion(bst.Get_Root(), 11);
    bst.Insertion(bst.Get_Root(), 14);

    // bst.Insertion(bst.Get_Root(), 10);
    // bst.Insertion(bst.Get_Root(), 6);
    //  bst.Insertion(bst.Get_Root(), 25);
    // bst.Insertion(bst.Get_Root(), 5);

    // bst.Insertion(bst.Get_Root(), 10);   
    // bst.Insertion(bst.Get_Root(), 6);
    // bst.Insertion(bst.Get_Root(), 29);
    // bst.Insertion(bst.Get_Root(), 5);
    // bst.Insertion(bst.Get_Root(), 28);
    // bst.Insertion(bst.Get_Root(), 27);
    // bst.Insertion(bst.Get_Root(), 26);
    // bst.Insertion(bst.Get_Root(), 25);
    // bst.Insertion(bst.Get_Root(), 24);
    // bst.Insertion(bst.Get_Root(), 23);
    // bst.Insertion(bst.Get_Root(), 22);

    // bst.Insertion(bst.Get_Root(), 9);
    // bst.Insertion(bst.Get_Root(), 5);

    //  bst.Insertion(bst.Get_Root(), 10);
    // bst.Insertion(bst.Get_Root(), 6);
    // bst.Insertion(bst.Get_Root(), 29);
    // bst.Insertion(bst.Get_Root(), 5);
    // bst.Insertion(bst.Get_Root(), 45);
    // bst.Insertion(bst.Get_Root(), 22);
    // bst.Insertion(bst.Get_Root(), 55);
    // bst.Insertion(bst.Get_Root(), 66);
    // bst.Insertion(bst.Get_Root(), 5);
    // bst.Insertion(bst.Get_Root(), 8);
    //  bst.Insertion(bst.Get_Root(), 4);
    // bst.Insertion(bst.Get_Root(), 54);
    bst.print(bst.Get_Root());
    cout<<endl;
   cout<< bst.count_nodes(bst.Get_Root(),20,0)<<endl;

   cout<<bst.right_leaves(bst.Get_Root());

   cout<<"------"<<endl;

     cout<<bst.left_most_node(bst.Get_Root())<<endl;
      cout<<"------"<<endl;
    
       int s=bst.min_diff(bst.Get_Root(),0);
    cout<<s<<endl;
  
    if (s==1)
    {
       cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    
    cout<< bst.min_diff(bst.Get_Root(),0)<<endl;
  
    return 0;

}