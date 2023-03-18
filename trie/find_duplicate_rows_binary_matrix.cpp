//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct TrieNode {
  bool leaf;
  TrieNode* children[2];
  TrieNode() : leaf(false) { children[0] = children[1] = 0; }
};

class Solution {
  void put(TrieNode* p, const vector<int>& line) {
    for (int e : line) {
      if (!p->children[e]) {
        p->children[e] = new TrieNode();
      }
      p = p->children[e];
    }
    p->leaf = true;
  }

  bool get(TrieNode* p, const vector<int>& line) {
    for (int e : line) {
      if (!p->children[e]) return false;
      p = p->children[e];
    }
    return p->leaf;
  }

 public:
  vector<int> repeatedRows(vector<vector<int>> matrix, int M, int N) {
    // Your code here
    TrieNode* root = new TrieNode();
    vector<int> ans;
    for (int i = 0; i < M; ++i) {
      if (get(root, matrix[i])) {
        ans.push_back(i);
      } else {
        put(root, matrix[i]);
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
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row);
    for (int i = 0; i < row; i++) {
      matrix[i].assign(col, 0);
      for (int j = 0; j < col; j++) {
        cin >> matrix[i][j];
      }
    }

    Solution ob;
    vector<int> ans = ob.repeatedRows(matrix, row, col);

    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
