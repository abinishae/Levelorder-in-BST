// { Driver Code Starts
//Initial Template for C++


// C program for different tree traversals 
#include <bits/stdc++.h> 
using namespace std; 


struct Node 
{ 
	int data; 
	struct Node* left, *right; 
	Node(int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
};


/* A utility function to insert a new node with given key in BST */
struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return new Node(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
}


vector<int> levelOrder(Node *root);


/* Driver program to test above functions */
int main() 
{
    int t;
    cin>>t;
    while(t--) 
    {
        Node *root= NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            root= insert(root,x);
        }
        
        vector <int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
	
	return 0;
}


// } Driver Code Ends


//User function Template for C++

vector<int> levelOrder(Node *r) 
{ 
  vector<int> a;
  queue<Node*> s;
  s. push(r);
  while(! s. empty()){
      Node*t = s. front();
      s. pop();
      if(t->left)
      s. push(t->left);
      if(t->right)
      s. push (t->right);
      a. push_back(t->data);
      
  }return a;
  
  
} 
