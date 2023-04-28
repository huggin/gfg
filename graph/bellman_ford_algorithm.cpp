//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  /*  Function to implement Bellman Ford
   *   edges: vector of vectors which represents the graph
   *   S: source vertex to start traversing graph with
   *   V: number of vertices
   */
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S) {
    // Code here
    vector<int> ans(V, 100000000);
    ans[S] = 0;
    vector<int> adj[V];
    for (int i = 0; i < edges.size(); ++i) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][0]].push_back(edges[i][2]);
    }
    for (int k = 0; k < V; ++k) {
      bool change = false;
      for (int i = 0; i < V; ++i) {
        for (int j = 0; j < adj[i].size(); j += 2) {
          if (ans[adj[i][j]] > ans[i] + adj[i][j + 1]) {
            ans[adj[i][j]] = ans[i] + adj[i][j + 1];
            change = true;
          }
        }
      }
      if (!change)
        break;
    }
    bool change = false;
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < adj[i].size(); j += 2) {
        if (ans[adj[i][j]] > ans[i] + adj[i][j + 1]) {
          ans[adj[i][j]] = ans[i] + adj[i][j + 1];
          change = true;
        }
      }
    }
    if (change)
      return vector<int>{-1};
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, m;
    cin >> N >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; ++i) {
      vector<int> temp;
      for (int j = 0; j < 3; ++j) {
        int x;
        cin >> x;
        temp.push_back(x);
      }
      edges.push_back(temp);
    }

    int src;
    cin >> src;

    Solution obj;
    vector<int> res = obj.bellman_ford(N, edges, src);

    for (auto x : res) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
