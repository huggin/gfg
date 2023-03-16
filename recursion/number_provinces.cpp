//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<int> v;

  void dfs(int k, vector<vector<int>>& adj) {
    v[k] = 1;
    for (int i = 0; i < adj[k].size(); ++i) {
      if (i == k) continue;
      if (!v[i] && adj[k][i] == 1) {
        dfs(i, adj);
      }
    }
  }

 public:
  int numProvinces(vector<vector<int>> adj, int V) {
    // code here
    v.assign(V, 0);
    int ans = 0;
    for (int i = 0; i < V; ++i) {
      if (!v[i]) {
        ++ans;
        dfs(i, adj);
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
    int V, x;
    cin >> V;

    vector<vector<int>> adj;

    for (int i = 0; i < V; i++) {
      vector<int> temp;
      for (int j = 0; j < V; j++) {
        cin >> x;
        temp.push_back(x);
      }
      adj.push_back(temp);
    }

    Solution ob;
    cout << ob.numProvinces(adj, V) << endl;
  }
  return 0;
}
// } Driver Code Ends
