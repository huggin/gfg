//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;
  Node() {
    data = 0;
    left = right = NULL;
  }
  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  vector<Node *> v1, v2;
  bool find(Node *p, int n, vector<Node *> &v) {
    if (!p)
      return false;
    if (p->data == n) {
      v.push_back(p);
      return true;
    }
    if (find(p->left, n, v)) {
      v.push_back(p);
      return true;
    }
    if (find(p->right, n, v)) {
      v.push_back(p);
      return true;
    }
    return false;
  }

public:
  // Function to return the lowest common ancestor in a Binary Tree.
  Node *lca(Node *root, int n1, int n2) {
    // Your code here
    v1.clear();
    v2.clear();
    if (!find(root, n1, v1))
      return NULL;
    find(root, n2, v2);
    for (int i = 0; i < v1.size(); ++i) {
      if (std::find(v2.begin(), v2.end(), v1[i]) != v2.end()) {
        return v1[i];
      }
    }
    return NULL;
  }
};

//{ Driver Code Starts.

Node *newNode(int val) {
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

// Function to Build Tree
Node *buildTree(string str) {
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // for(string i:ip)
  //     cout<<i<<" ";
  // cout<<endl;
  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size()) {
    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N") {
      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N") {
      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// Function for Inorder Traversal
void printInorder(Node *root) {
  if (!root)
    return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d ", &a, &b);
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    Solution ob;
    cout << ob.lca(root, a, b)->data << endl;
  }
  return 0;
}

// } Driver Code Ends
