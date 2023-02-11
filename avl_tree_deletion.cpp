//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data, height;
  Node *left, *right;
  Node(int x) {
    data = x;
    height = 1;
    left = right = NULL;
  }
};

int setHeights(Node* n) {
  if (!n) return 0;
  n->height = 1 + max(setHeights(n->left), setHeights(n->right));
  return n->height;
}

Node* buildTree(string str) {
  // Corner Case
  if (str.length() == 0 || str[0] == 'N') return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;) ip.push_back(str);

  // Create the root of the tree
  Node* root = new Node(stoi(ip[0]));

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
      currNode->left = new Node(stoi(currVal));

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
      currNode->right = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  setHeights(root);
  return root;
}

bool isBST(Node* n, int lower, int upper) {
  if (!n) return 1;
  if (n->data <= lower || n->data >= upper) return 0;
  return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper);
}

pair<int, bool> isBalanced(Node* n) {
  if (!n) return pair<int, bool>(0, 1);

  pair<int, bool> l = isBalanced(n->left);
  pair<int, bool> r = isBalanced(n->right);

  if (abs(l.first - r.first) > 1) return pair<int, bool>(0, 0);

  return pair<int, bool>(1 + max(l.first, r.first), l.second && r.second);
}

bool isBalancedBST(Node* root) {
  if (!isBST(root, INT_MIN, INT_MAX))
    cout << "BST voilated, inorder traversal : ";

  else if (!isBalanced(root).second)
    cout << "Unbalanced BST, inorder traversal : ";

  else
    return 1;
  return 0;
}

void printInorder(Node* n) {
  if (!n) return;
  printInorder(n->left);
  cout << n->data << " ";
  printInorder(n->right);
}

struct Node* deleteNode(struct Node* root, int data);

int main() {
  int t;
  cin >> t;
  getchar();

  while (t--) {
    string s;
    getline(cin, s);
    Node* root = buildTree(s);

    int n;
    cin >> n;
    int ip[n];
    for (int i = 0; i < n; i++) cin >> ip[i];

    for (int i = 0; i < n; i++) {
      root = deleteNode(root, ip[i]);

      if (!isBalancedBST(root)) break;
    }

    if (root == NULL)
      cout << "null";
    else
      printInorder(root);
    cout << endl;

    getline(cin, s);  // to deal with newline char
  }
  return 1;
}

// } Driver Code Ends

/* Node is as follows:

struct Node
{
        int data, height;
        Node *left, *right;
        Node(int x)
        {
                data = x;
                height = 1;
                left = right = NULL;
        }
};

*/

int height(Node* p) {
  if (!p) return 0;
  return p->height;
}

Node* leftRotate(Node* y) {
  Node* x = y->right;
  Node* t = x->left;
  y->right = t;
  x->left = y;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

Node* rightRotate(Node* y) {
  Node* x = y->left;
  Node* t = x->right;
  y->left = t;
  x->right = y;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

int getBalance(Node* p) {
  if (!p) return 0;
  return height(p->left) - height(p->right);
}

Node* minValueNode(Node* p) {
  while (p->left) {
    p = p->left;
  }
  return p;
}

Node* deleteNode(Node* root, int data) {
  // add code here,
  if (!root) return NULL;
  if (root->data < data)
    root->right = deleteNode(root->right, data);
  else if (root->data > data)
    root->left = deleteNode(root->left, data);
  else {
    if (!root->left || !root->right) {
      Node* temp = root->left ? root->left : root->right;
      if (!temp) {
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
        delete temp;
      }
    } else {
      Node* p = minValueNode(root->right);
      root->data = p->data;
      root->right = deleteNode(root->right, p->data);
    }
  }
  if (!root) return NULL;

  root->height = max(height(root->left), height(root->right)) + 1;
  int balance = getBalance(root);

  if (balance > 1) {
    if (getBalance(root->left) < 0) root->left = leftRotate(root->left);
    root = rightRotate(root);
  }

  if (balance < -1) {
    if (getBalance(root->right) > 0) root->right = rightRotate(root->right);
    root = leftRotate(root);
  }
  return root;
}
