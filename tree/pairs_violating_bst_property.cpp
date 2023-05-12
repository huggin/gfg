//{ Driver Code Starts
// Author- Sajal Agrawal
// sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int indx, ans;

struct Node {
  int data;
  Node *left, *right;

  Node(int d) {
    data = d;
    left = right = NULL;
  }
};
int pairsViolatingBST(Node *root, int n);
void insert(Node *root, int a, int b, char ch);

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    indx = 0;
    ans = 0;
    Node *root = NULL;
    for (int j = 0; j < n; j++) {
      int a, b;
      char ch;
      cin >> a >> b >> ch;
      if (root == NULL) {
        root = new Node(a);
        switch (ch) {
        case 'L':
          root->left = new Node(b);
          break;
        case 'R':
          root->right = new Node(b);
          break;
        }
      } else {
        insert(root, a, b, ch);
      }
    }
    cout << pairsViolatingBST(root, n) << "\n";
  }

  return 0;
}

void insert(Node *root, int a, int b, char ch) {
  if (root == NULL)
    return;
  if (root->data == a) {
    switch (ch) {
    case 'L':
      root->left = new Node(b);
      break;
    case 'R':
      root->right = new Node(b);
      break;
    }
  } else {
    insert(root->left, a, b, ch);
    insert(root->right, a, b, ch);
  }
}

// } Driver Code Ends

/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */

void inOrder(Node *p, vector<int> &v) {
  if (!p)
    return;
  inOrder(p->left, v);
  v.push_back(p->data);
  inOrder(p->right, v);
}

/*You are required to complete below method */
int pairsViolatingBST(Node *root, int n) {
  /*Your code here */
  vector<int> v;
  inOrder(root, v);
  int ans = 0;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      if (v[i] > v[j]) {
        ++ans;
      }
    }
  }
  return ans;
}
