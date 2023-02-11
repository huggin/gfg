//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<vector<char>> b;
  int n, m;
  string w;
  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int v[51][51];

  bool solve(int i, int j, int t) {
    if (t == w.size() - 1 && b[i][j] == w[t]) return true;
    if (b[i][j] != w[t]) return false;
    for (int k = 0; k < 8; ++k) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && v[ni][nj] == 0) {
        v[ni][nj] = 1;
        if (solve(ni, nj, t + 1)) return true;
        v[ni][nj] = 0;
      }
    }
    return false;
  }

 public:
  vector<string> wordBoggle(vector<vector<char>>& board,
                            vector<string>& dictionary) {
    // Code here
    b = board;
    n = b.size();
    m = b[0].size();
    vector<string> ans;
    for (auto& c : dictionary) {
      bool found = false;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (b[i][j] == c[0]) {
            w = c;
            memset(v, 0, sizeof(v));
            v[i][j] = 1;
            if (solve(i, j, 0)) {
              ans.push_back(c);
              found = true;
              break;
            }
          }
        }
        if (found) break;
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
    int N;
    cin >> N;
    vector<string> dictionary;
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      dictionary.push_back(s);
    }

    int R, C;
    cin >> R >> C;
    vector<vector<char>> board(R);
    for (int i = 0; i < R; i++) {
      board[i].resize(C);
      for (int j = 0; j < C; j++) cin >> board[i][j];
    }
    Solution obj;
    vector<string> output = obj.wordBoggle(board, dictionary);
    if (output.size() == 0)
      cout << "-1";
    else {
      sort(output.begin(), output.end());
      for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
    }
    cout << endl;
  }
}

// } Driver Code Ends//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<vector<char>> b;
  int n, m;
  string w;
  int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int v[51][51];

  bool solve(int i, int j, int t) {
    if (t == w.size() - 1 && b[i][j] == w[t]) return true;
    if (b[i][j] != w[t]) return false;
    for (int k = 0; k < 8; ++k) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && v[ni][nj] == 0) {
        v[ni][nj] = 1;
        if (solve(ni, nj, t + 1)) return true;
        v[ni][nj] = 0;
      }
    }
    return false;
  }

 public:
  vector<string> wordBoggle(vector<vector<char>>& board,
                            vector<string>& dictionary) {
    // Code here
    b = board;
    n = b.size();
    m = b[0].size();
    vector<string> ans;
    for (auto& c : dictionary) {
      bool found = false;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (b[i][j] == c[0]) {
            w = c;
            memset(v, 0, sizeof(v));
            v[i][j] = 1;
            if (solve(i, j, 0)) {
              ans.push_back(c);
              found = true;
              break;
            }
          }
        }
        if (found) break;
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
    int N;
    cin >> N;
    vector<string> dictionary;
    for (int i = 0; i < N; ++i) {
      string s;
      cin >> s;
      dictionary.push_back(s);
    }

    int R, C;
    cin >> R >> C;
    vector<vector<char>> board(R);
    for (int i = 0; i < R; i++) {
      board[i].resize(C);
      for (int j = 0; j < C; j++) cin >> board[i][j];
    }
    Solution obj;
    vector<string> output = obj.wordBoggle(board, dictionary);
    if (output.size() == 0)
      cout << "-1";
    else {
      sort(output.begin(), output.end());
      for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
    }
    cout << endl;
  }
}

// } Driver Code Ends
