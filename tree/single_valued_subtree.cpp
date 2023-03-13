//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
  int data;
  Node* left;
  Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
  Node* temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
  // Corner Case
  if (str.length() == 0 || str[0] == 'N') return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;) ip.push_back(str);

  // Create the root of the tree
  Node* root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node*> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size()) {
    // Get and remove the front of the queue
    Node* currNode = queue.front();
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
    if (i >= ip.size()) break;
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

// } Driver Code Ends
// User function Template for C++

/* Tree Node
struct Node
{
        int data;
        Node* left;
        Node* right;
};*/

class Solution {
  int ans = 0;
  int solve(Node* p) {
    if (!p) return 0;
    if (!p->left && !p->right) {
      ++ans;
      return 1;
    }
    int l = solve(p->left);
    int r = solve(p->right);

    if (l == 0 && !p->left && r != 0) {
      if (p->data == p->right->data) {
        ++ans;
        return 1;
      } else {
        return 0;
      }
    }
    if (r == 0 && !p->right && l != 0) {
      if (p->data == p->left->data) {
        ++ans;
        return 1;
      } else {
        return 0;
      }
    }
    // cout << p->data << p->right->data << p->left->data << endl;
    if (l != 0 && r != 0 && p->data == p->right->data &&
        p->data == p->left->data) {
      ++ans;
      return 1;
    }
    return 0;
  }

 public:
  int singlevalued(Node* root) {
    // code here
    solve(root);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  getchar();
  while (t--) {
    string inp;
    getline(cin, inp);

    Solution ob;

    struct Node* root = buildTree(inp);
    cout << ob.singlevalued(root) << "\n";
  }
  return 0;
}

// } Driver Code Ends
