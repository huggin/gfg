//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct TrieNode {
  int size;
  TrieNode* children[26];
  TrieNode(int sz = 0) : size(sz) { memset(children, 0, sizeof(children)); }
};

class Solution {
  void put(TrieNode* root, const string& s) {
    TrieNode* p = root;
    for (char c : s) {
      int d = c - 'a';
      if (!p->children[d]) {
        p->children[d] = new TrieNode(1);
      } else {
        p->children[d]->size++;
      }
      p = p->children[d];
    }
  }

 public:
  int klengthpref(string arr[], int n, int k, string str) {
    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; ++i) {
      put(root, arr[i]);
    }
    TrieNode* p = root;
    for (int i = 0; i < k; ++i) {
      int d = str[i] - 'a';
      if (!p->children[d]) return 0;
      p = p->children[d];
    }
    return p->size;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) {
      string s;
      cin >> arr[i];
    }
    int k;
    cin >> k;
    string str;
    cin >> str;

    Solution ob;
    cout << ob.klengthpref(arr, n, k, str) << endl;
  }
  return 0;
}

// } Driver Code Ends
