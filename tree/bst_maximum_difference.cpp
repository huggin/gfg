//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
  int data;
  Node *right;
  Node *left;

  Node(int x) {
    data = x;
    right = NULL;
    left = NULL;
  }
};

Node *insert(Node *tree, int val) {
  Node *temp = NULL;
  if (tree == NULL)
    return new Node(val);

  if (val < tree->data) {
    tree->left = insert(tree->left, val);
  } else if (val > tree->data) {
    tree->right = insert(tree->right, val);
  }

  return tree;
}

// } Driver Code Ends
// User function Template for C++

class Solution {
  int get(Node *p) {
    if (!p)
      return 0;
    int a = get(p->left);
    int b = get(p->right);
    if (a == 0)
      return b + p->data;
    if (b == 0)
      return a + p->data;
    return min(a + p->data, b + p->data);
  }

public:
  int maxDifferenceBST(Node *root, int target) {
    // Code here
    int a = 0;
    while (root && root->data != target) {
      a += root->data;
      if (root->data > target) {
        root = root->left;
      } else {
        root = root->right;
      }
    }
    if (!root)
      return -1;
    auto p = get(root);
    return a - p + root->data;
  }
};

//{ Driver Code Starts.

int main() {
  int T;
  cin >> T;
  while (T--) {
    Node *root = NULL;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int k;
      cin >> k;
      root = insert(root, k);
    }

    int target;
    cin >> target;
    Solution ob;
    cout << ob.maxDifferenceBST(root, target);
    cout << endl;
  }
}
// } Driver Code Ends
