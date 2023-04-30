//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node {
public:
  int data;
  Node *left, *right;
  Node(int data) {
    this->data = data;
    this->left = this->right = NULL;
  }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

// } Driver Code Ends
// User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

class Solution {
public:
  // function to construct tree from string
  Node *treeFromString(string str) {
    // code here
    if (str.empty()) {
      return NULL;
    }
    auto it = str.find("(");
    Node *ret = new Node(atoi(str.substr(0, it).c_str()));
    int count = 0;
    for (int i = it; i < str.size(); ++i) {
      if (str[i] == '(') {
        ++count;
      } else if (str[i] == ')') {
        if (--count == 0) {
          ret->left = treeFromString(str.substr(it + 1, i - 1 - it));
          if (i + 1 < str.size() && str[i + 1] == '(') {
            ret->right = treeFromString(str.substr(i + 2, str.size() - i - 2));
          }
          break;
        }
      }
    }
    return ret;
  }
};

//{ Driver Code Starts.

// Driver Code
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    Solution obj;
    Node *root = obj.treeFromString(str);
    inorder(root);
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
