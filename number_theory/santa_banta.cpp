//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void precompute();
int helpSanta(int n, int m, vector<vector<int>>& g);

int main() {
  int t;
  cin >> t;
  precompute();
  while (t--) {
    int n, e, u, v;
    cin >> n >> e;
    vector<vector<int>> g(n + 10);

    for (int i = 0; i < e; i++) {
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    cout << helpSanta(n, e, g) << endl;
  }
}

// } Driver Code Ends

vector<int> prime;
const int MAX = 1000005;

void dfs(vector<vector<int>>& g, int k, vector<int>& marked, int& count) {
  ++count;
  marked[k] = 1;
  for (int w : g[k]) {
    if (!marked[w]) dfs(g, w, marked, count);
  }
}

void precompute() {
  // Code here
  vector<bool> vb(MAX, true);
  vb[0] = vb[1] = false;
  for (long long i = 2; i <= MAX; ++i) {
    if (vb[i]) {
      prime.push_back(i);
      for (long long j = i * i; j <= MAX; j += i) vb[j] = false;
    }
  }
}
int helpSanta(int n, int m, vector<vector<int>>& g) {
  // Code here
  if (m == 0) return -1;
  int rank = 1;
  vector<int> marked(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!marked[i]) {
      int count = 0;
      dfs(g, i, marked, count);
      rank = max(rank, count);
    }
  }

  return prime[rank - 1];
}
