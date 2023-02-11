//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Node {
  Node* next[256];
  bool isLeaf;
  Node(bool t = false) : isLeaf(t) { memset(next, 0, sizeof(next)); }
};

class Solution {
  Node* root = NULL;
  Node* put(const string& w) { return put(root, w, 0); }

  Node* put(Node* p, const string& w, int d) {
    if (!p) p = new Node();
    if (d == w.size()) {
      p->isLeaf = true;
      return p;
    }
    char c = w[d];
    p->next[c] = put(p->next[c], w, d + 1);
    return p;
  }

  bool get(const string& w) { return get(root, w, 0); }

  bool get(Node* p, const string& w, int d) {
    if (!p) return false;
    if (w.size() == d) return p->isLeaf;
    if (!p->isLeaf) return false;
    char c = w[d];
    return get(p->next[c], w, d + 1);
  }

 public:
  string longestString(vector<string>& words) {
    // code here
    root = new Node(true);
    string ans;
    for (auto& w : words) put(w);
    for (auto& w : words) {
      bool ok = get(w);
      // cout << w << ' ' << ok << endl;
      if (ok) {
        if (w.size() > ans.size() || w.size() == ans.size() && w < ans) {
          ans = w;
        }
      }
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
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    Solution obj;
    string w = obj.longestString(v);
    cout << w << "\n";
  }
  return 0;
}

// } Driver Code Ends
