//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct TrieNode {
  TrieNode *children[2];
  int value;
  TrieNode() : value(0) { memset(children, 0, sizeof(children)); }
};

class Solution {
  void put(TrieNode* root, int d) {
    for (int i = 31; i >= 0; --i) {
      bool b = d & (1 << i);
      if (!root->children[b]) {
        root->children[b] = new TrieNode();
      }
      root = root->children[b];
    }
    root->value = d;
  }

  int get(TrieNode *root, int d) {
    for (int i = 31; i >= 0; --i) {
      bool b = d & (1 << i);
      if (root->children[1 - b]) {
        root = root->children[1 - b];
      } else {
        root = root->children[b];
      }
    }
    return d ^ root->value;
  }

public:
  int maxSubarrayXOR(int N, int arr[]) {
    // code here
    TrieNode *root = new TrieNode();
    put(root, 0);
    int prefix = 0;
    int ans = INT_MIN;
    for (int i = 0; i < N; ++i) {
      prefix ^= arr[i];
      ans = max(ans, prefix);
      put(root, prefix);
      ans = max(ans, get(root, prefix));
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, X;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    Solution ob;
    cout << ob.maxSubarrayXOR(N, arr) << endl;
  }
  return 0;
}

// } Driver Code Ends
