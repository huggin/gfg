//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Node {
  int size;
  Node* next[26];
  Node(int sz = 0) : size(sz) { memset(next, 0, sizeof(next)); }
};

class Solution {
  vector<string> ans;

  Node* put(Node* p, const string& s, int d) {
    if (!p) p = new Node();
    ++p->size;
    if (s.size() == d) {
      return p;
    }
    int i = s[d] - 'a';
    p->next[i] = put(p->next[i], s, d + 1);
    return p;
  }

 public:
  vector<string> findPrefixes(string arr[], int n) {
    // code here
    Node* root = new Node(0);
    for (int i = 0; i < n; ++i) {
      put(root, arr[i], 0);
    }
    for (int i = 0; i < n; ++i) {
      int len = 1;
      Node* p = root->next[arr[i][0] - 'a'];
      while (p->size > 1) {
        p = p->next[arr[i][len] - 'a'];
        ++len;
      }
      ans.push_back(arr[i].substr(0, len));
    }
    return ans;
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
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution ob;
    vector<string> ans = ob.findPrefixes(arr, n);

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

    cout << "\n";
  }

  return 0;
}

// } Driver Code Ends
