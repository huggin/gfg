//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = NULL;
    right = NULL;
  }
};

void printInorder(Node *node) {
  if (node == NULL)
    return;
  printInorder(node->left);
  cout << node->data << " ";
  printInorder(node->right);
}

Node *constructBinaryTree(int pre[], int preMirror[], int size);

// Driver program to test above functions
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int preOrder[n];
    int preOrderMirror[n];
    for (int i = 0; i < n; i++)
      cin >> preOrder[i];
    for (int i = 0; i < n; i++)
      cin >> preOrderMirror[i];
    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends

/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the
// new binary tree formed
Node *construct(int pre[], int preMirror[], int l1, int r1, int l2, int r2) {
  if (l1 > r1) {
    return NULL;
  }
  if (l1 == r1) {
    return new Node(pre[l1]);
  }
  Node *p = new Node(pre[l1]);
  int idx =
      find(preMirror + l2 + 1, preMirror + r2 + 1, pre[l1 + 1]) - preMirror;
  if (idx == l2 + 1) {
    p->left = construct(pre, preMirror, l1 + 1, r1, l2 + 1, r2);
  } else {
    int right_idx = find(pre + l1 + 1, pre + r1 + 1, preMirror[l2 + 1]) - pre;
    p->left = construct(pre, preMirror, l1 + 1, right_idx - 1, idx, r2);
    p->right = construct(pre, preMirror, right_idx, r1, l2 + 1, idx - 1);
  }

  return p;
}

Node *constructBinaryTree(int pre[], int preMirror[], int size) {
  // Code here
  return construct(pre, preMirror, 0, size - 1, 0, size - 1);
}
