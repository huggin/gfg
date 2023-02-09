//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *random;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    random = NULL;
	}
};
int checkcloned(Node* a, Node *b)
{
	if ((a == NULL and b == NULL))
		return 1;

	if (a != NULL && b != NULL)
	{
		int t = (a->data == b->data && checkcloned(a->left, b->left) && checkcloned(a->right, b->right));

		if (a->random != NULL && b->random != NULL)
			return (t && a->random->data == b->random->data);
		if (a->random == b->random)
			return t;

		return 0;
	}

	return 0;

}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution{
    Node* clone(Node* p, unordered_map<Node*, Node*>& m) {
        if (!p) return NULL;
        Node* n = new Node(p->data);
        m[p] = n;
        n->left = clone(p->left, m);
        n->right = clone(p->right, m);
        return n;
    }
    
    void fill(Node* p, Node* n, unordered_map<Node*, Node*>& m) {
        if (!p) return;
        if (p->random) {
            n->random = m[p->random];
        }
        fill(p->left, n->left, m);
        fill(p->right, n->right, m);
    }
    
    void print(Node* p) {
        if (!p) return;
        cout << p->data << ' ';
        print(p->left);
        print(p->right);
        cout << endl;
    }
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
    Node* cloneTree(Node* tree)
    {
       //Your code here
       unordered_map<Node*, Node*> m;
       Node* p = clone(tree, m);
       //print(tree);
       //print(p);
       
       fill(tree, p, m);
       return p;
    }
};


//{ Driver Code Starts.
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L'){
          parent->left = child;
           m[n2]  = child;
        }
        else if(lr=='R'){
          parent->right = child;
           m[n2]  = child;
        }
        else{
          parent->random = m[n2];
        }


     }
     Solution obj;
     Node *t = obj.cloneTree(root);
     if(t==root)
        cout<<0<<endl;
     else
     cout<<checkcloned(root,t);
     cout<<"\n";
  }
  return 0;
}


// } Driver Code Ends
