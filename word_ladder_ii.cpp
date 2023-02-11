//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  bool neighbor(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;
    int ans = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) ++ans;
    }
    return ans == 1;
  }

  vector<string> vs;

  void dfs(vector<vector<int>>& to, int dest, int src, vector<string>& vertex,
           vector<vector<string>>& ans) {
    if (dest == src) {
      ans.push_back(vs);
      return;
    }
    for (int i = 0; i < to[dest].size(); ++i) {
      vs.push_back(vertex[to[dest][i]]);
      dfs(to, to[dest][i], src, vertex, ans);
      vs.pop_back();
    }
  }

 public:
  vector<vector<string>> findSequences(string beginWord, string endWord,
                                       vector<string>& wordList) {
    // Code here
    vector<string> vertex(wordList);
    int n = vertex.size();
    int s = -1;
    auto it = find(wordList.begin(), wordList.end(), beginWord);
    if (it == wordList.end()) {
      vertex.push_back(beginWord);
      ++n;
      s = n - 1;
    } else {
      s = it - wordList.begin();
    }
    it = find(wordList.begin(), wordList.end(), endWord);
    vector<vector<string>> ans;
    if (it == wordList.end()) {
      return ans;
    }
    int dest = it - wordList.begin();
    vector<int> adj[n];
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (neighbor(vertex[i], vertex[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    vector<vector<int>> to(n);
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
      int c = Q.front();
      Q.pop();
      for (auto w : adj[c]) {
        if (dist[w] == INT_MAX) {
          to[w].push_back(c);
          dist[w] = dist[c] + 1;
          Q.push(w);
        } else if (dist[w] == dist[c] + 1) {
          to[w].push_back(c);
        }
      }
    }
    if (dist[dest] == INT_MAX) return ans;
    vs.clear();

    vs.push_back(vertex[dest]);

    dfs(to, dest, s, vertex, ans);
    for (int i = 0; i < ans.size(); ++i) {
      reverse(ans[i].begin(), ans[i].end());
    }

    return ans;
  }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b) {
  string x = "", y = "";
  for (string i : a) x += i;
  for (string i : b) y += i;

  return x < y;
}

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++) cin >> wordList[i];
    string startWord, targetWord;
    cin >> startWord >> targetWord;
    Solution obj;
    vector<vector<string>> ans =
        obj.findSequences(startWord, targetWord, wordList);
    if (ans.size() == 0)
      cout << -1 << endl;
    else {
      sort(ans.begin(), ans.end(), comp);
      for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
          cout << ans[i][j] << " ";
        }
        cout << endl;
      }
    }
  }
  return 0;
}
// } Driver Code Ends
