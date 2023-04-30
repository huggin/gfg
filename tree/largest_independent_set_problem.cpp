//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

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

  // Create the root of the tree
  Node *root = new Node(stoi(ip[0]));

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
      currNode->left = new Node(stoi(currVal));

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
      currNode->right = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// } Driver Code Ends
// you are required to complete this function
// function should return the size of the
// Largest Independent set in the tree

// User function template for C++

/*
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

unordered_map<Node *, int> dp[2];

int solve(Node *p, int used) {
  if (!p)
    return 0;
  if (dp[used].find(p) != dp[used].end()) {
    return dp[used][p];
  }
  int &ans = dp[used][p];
  if (used == 1) {
    auto l = solve(p->left, 0);
    auto r = solve(p->right, 0);
    ans = 1 + l + r;
  } else {
    auto l1 = solve(p->left, 1);
    auto r1 = solve(p->right, 1);
    auto l0 = solve(p->left, 0);
    auto r0 = solve(p->right, 0);
    ans = max({l1 + r1, l1 + r0, l0 + r1, l0 + r0});
  }
  return ans;
}

int LISS(Node *root) {
  // Code here
  if (!root)
    return 0;
  return max(solve(root, 1), solve(root, 0));
}

//{ Driver Code Starts.
int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    cout << LISS(root) << endl;
  }
  return 0;
}

// } Driver Code Ends
