//{ Driver Code Starts
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
    string currVal = "";
    currVal += ip[i];

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

void preorder(Node *root, vector<int> &temp) {
  if (!root) {
    return;
  }
  // cout<<root->data<<" ";
  temp.push_back(root->data);
  preorder(root->left, temp);
  preorder(root->right, temp);
}

// } Driver Code Ends
// function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
        int data;
        struct Node* left, *right;
};
*/
unordered_map<Node *, int> h;

int postOrder(Node *p) {
  if (!p)
    return 0;
  int l = postOrder(p->left);
  int r = postOrder(p->right);
  h[p] = max(l, r) + 1;
  return h[p];
}

unordered_map<Node *, int> used;

bool solve(Node *p, Node *q) {
  if (!p && !q)
    return true;
  // if (used[p] == 1 || used[q] == 1) return false;
  if (!p && q || p && !q)
    return false;
  if (p->data == q->data && solve(p->left, q->left) &&
      solve(p->right, q->right)) {
    // if (used[p] == 0 && used[q] == 0) {
    // used[p] = 1;
    // used[q] = 1;
    return true;
    //}
  }
  return false;
}

// you are required to complete this function
// the function and return an vector of Node
// which contains all the duplicate sub-tree
vector<Node *> printAllDups(Node *root) {
  // Code here
  h.clear();
  used.clear();
  postOrder(root);

  vector<Node *> ans;
  vector<pair<int, Node *>> v;
  for (auto c : h) {
    v.emplace_back(c.second, c.first);
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      if (v[i].first != v[j].first) {
        break;
      }
      if (used[v[i].second] || used[v[j].second])
        continue;
      if (solve(v[i].second, v[j].second)) {
        used[v[i].second] = 1;
        used[v[j].second] = 1;
        ans.push_back(v[i].second);
      }
    }
  }
  auto it = unique(ans.begin(), ans.end(), solve);
  ans.erase(it, ans.end());
  return ans;
}

//{ Driver Code Starts.

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string treeString;
    getline(cin >> ws, treeString);
    // cin.ignore();
    // cin.clear();
    // cout<<treeString<<"\n";

    Node *root = buildTree(treeString);
    vector<Node *> res = printAllDups(root);

    vector<vector<int>> ans;

    for (int i = 0; i < res.size(); i++) {
      vector<int> temp;
      preorder(res[i], temp);
      ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
      }
      cout << "\n";
    }
    // cout<<"\n";
  }
  return 0;
}

// } Driver Code Ends
