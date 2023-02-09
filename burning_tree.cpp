//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


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

        // Get the current Node's value from the string
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<Node*> v;
    unordered_map<Node*, int> m;
    
    bool find(Node* p, int target) {
        if (!p) return false;
        if (p->data == target) {
            v.push_back(p);
            return true;
        }
        bool ans = find(p->left, target);
        if (ans) {
            v.push_back(p);
            return ans;
        }
        ans = find(p->right, target);
        if (ans) {
            v.push_back(p);
        }
        return ans;
    }
    
    int height(Node *p) {
        if (!p) return 0;
        if (m.find(p) != m.end()) {
            return m[p];
        }
        int l = height(p->left);
        int r = height(p->right);
        m[p] = max(l, r) + 1;
        return m[p];
    }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        find(root, target);
        if (v.size() == 1) {
            return height(root) - 1;
        }
        
        int n = v.size();
        Node* p = v[0];
        int ans = height(v[0]) - 1;

        for(int i = 1; i<n; ++i) {
            if (v[i]->left == p) {
                ans = max(ans, height(v[i]->right) + i);
            } else {
                ans = max(ans, height(v[i]->left) + i);
            }
            p = v[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
