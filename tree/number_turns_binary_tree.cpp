//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

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

  // Creating vector of strings from input string after spliting by space
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
      // Create the left child for the current Node
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
// User function template for C++
/*
Structure of the node of the tree is as follows
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution {
  vector<Node *> p1, p2;

  Node *find(Node *p, int target, vector<Node *> &v) {
    if (!p)
      return NULL;
    if (p->data == target) {
      v.push_back(p);
      return p;
    }
    Node *ret = find(p->left, target, v);
    if (ret) {
      v.push_back(p);
      return ret;
    }
    ret = find(p->right, target, v);
    if (ret) {
      v.push_back(p);
    }
    return ret;
  }

public:
  // function should return the number of turns required to go from first node
  // to second node
  int NumberOFTurns(struct Node *root, int first, int second) {
    // Your code goes here
    p1.clear();
    p2.clear();
    Node *p = find(root, first, p1);
    Node *q = find(root, second, p2);
    int n1 = p1.size();
    int n2 = p2.size();
    if (n1 > n2) {
      swap(p1, p2);
      swap(n1, n2);
    }

    Node *parent = NULL;
    int pos = -1;
    for (int i = 0; i < n1; ++i) {
      if (p1[i] == p2[i + n2 - n1]) {
        parent = p1[i];
        pos = i;
        break;
      }
    }
    if (pos == 0) {
      int dir = -1;
      int ans2 = 0;
      for (int j = pos - 1 + n2 - n1; j >= 0; --j) {
        if (p2[j] == parent->left) {
          if (dir == 1) {
            ++ans2;
          }
          dir = 0;
        } else {
          if (dir == 0) {
            ++ans2;
          }
          dir = 1;
        }
        parent = p2[j];
      }
      if (ans2 == 0)
        return -1;
      return ans2;
    }
    // cout << pos << ' ' << parent->data << endl;
    int ans = 0;
    int dir = -1;
    for (int j = pos - 1; j >= 0; --j) {
      // cout << parent->data << ' ' << p1[j]->data << endl;
      if (p1[j] == parent->left) {
        if (dir == 1) {
          ++ans;
        }
        dir = 0;
      } else {
        if (dir == 0) {
          ++ans;
        }
        dir = 1;
      }
      parent = p1[j];
    }
    dir = -1;
    parent = p1[pos];
    int ans2 = 0;
    for (int j = pos - 1 + n2 - n1; j >= 0; --j) {
      if (p2[j] == parent->left) {
        if (dir == 1) {
          ++ans2;
        }
        dir = 0;
      } else {
        if (dir == 0) {
          ++ans2;
        }
        dir = 1;
      }
      parent = p2[j];
    }
    return ans + ans2 + 1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  struct Node *child;
  scanf("%d ", &t);
  while (t--) {
    string s;
    getline(cin, s);
    Node *root = buildTree(s);
    int turn, first, second;
    cin >> first >> second;
    Solution ob;
    if ((turn = ob.NumberOFTurns(root, first, second)))
      cout << turn << endl;
    else
      cout << "-1\n";
    cin.ignore();
  }
  return 0;
}

// } Driver Code Ends
