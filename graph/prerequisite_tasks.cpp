//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> visited;
  vector<int> on;
  bool cycle;

  void dfs(int v, vector<int> adj[]) {
    if (cycle)
      return;
    visited[v] = 1;
    on[v] = 1;
    for (auto w : adj[v]) {
      if (!visited[w]) {
        dfs(w, adj);
      } else {
        if (on[w])
          cycle = true;
      }
    }
    on[v] = 0;
  }

public:
  bool isPossible(int N, vector<pair<int, int>> &p) {
    // Code here
    vector<int> adj[N];
    for (int i = 0; i < p.size(); ++i) {
      adj[p[i].second].push_back(p[i].first);
    }
    visited.assign(N, 0);
    on.assign(N, 0);
    cycle = false;
    for (int i = 0; i < N; ++i) {
      dfs(i, adj);
    }
    return !cycle;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N, P;
    vector<pair<int, int>> prerequisites;
    cin >> N;
    cin >> P;
    for (int i = 0; i < P; ++i) {
      int x, y;
      cin >> x >> y;
      prerequisites.push_back(make_pair(x, y));
    }
    // string s;
    // cin>>s;
    Solution ob;
    if (ob.isPossible(N, prerequisites))
      cout << "Yes";
    else
      cout << "No";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
