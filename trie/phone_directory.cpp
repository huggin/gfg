//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Node {
  Node* next[256];
  int val;
  Node(int v = 0) : val(v) { memset(next, 0, sizeof(next)); }
};

vector<vector<string>> ans;
vector<string> vs;

Node* put(Node* p, const string& s, int d) {
  if (!p) p = new Node();
  if (d == s.size()) {
    p->val = 1;
    return p;
  }
  char c = s[d];
  p->next[c] = put(p->next[c], s, d + 1);
  return p;
}

void solve(Node* p, string& prefix) {
  if (p->val == 1) {
    vs.push_back(prefix);
  }
  for (int i = 0; i < 256; ++i) {
    if (p->next[i]) {
      prefix.push_back(i);
      solve(p->next[i], prefix);
      prefix.pop_back();
    }
  }
}

void get(Node* p, const string& s) {
  bool end = false;
  for (int i = 0; i < s.size(); ++i) {
    if (end || !p->next[s[i]]) {
      ans.push_back(vector<string>{"0"});
      end = true;
    } else {
      string t = s.substr(0, i + 1);
      solve(p->next[s[i]], t);
      ans.push_back(vs);
      vs.clear();
      p = p->next[s[i]];
    }
  }
}

class Solution {
 public:
  vector<vector<string>> displayContacts(int n, string contact[], string s) {
    // code here
    Node* root = new Node(1);
    for (int i = 0; i < n; ++i) {
      root = put(root, contact[i], 0);
    }
    ans.clear();
    vs.clear();
    get(root, s);
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
    string contact[n], s;
    for (int i = 0; i < n; i++) cin >> contact[i];
    cin >> s;

    Solution ob;
    vector<vector<string>> ans = ob.displayContacts(n, contact, s);
    for (int i = 0; i < s.size(); i++) {
      for (auto u : ans[i]) cout << u << " ";
      cout << "\n";
    }
  }
  return 0;
}
// } Driver Code Ends
