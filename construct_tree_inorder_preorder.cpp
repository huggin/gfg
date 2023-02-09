//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    Node *build(int in[], int l1, int r1, int pre[], int l2, int r2) {
        if (l1 > r1) return NULL;
        Node *p = new Node(pre[l2]);
        int k = find(in+l1, in+r1+1, pre[l2]) - in;
        p->left = build(in, l1, k - 1, pre, l2+1, l2 + k-1 - l1 + 1);
        p->right = build(in, k+1, r1, pre, l2+1+k-l1,r2);
        return p;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return build(in, 0, n-1, pre, 0, n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
