//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int water_flow(vector<vector<int>> &mat, int N, int M) {
    // Write your code here.
    vector<vector<int>> o(N, vector<int>(M)), s(N, vector<int>(M));
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    queue<int> Q;
    vector<vector<int>> marked(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
      o[i][0] = 1;
      marked[i][0] = 1;
      Q.push(i);
      Q.push(0);
    }
    for (int j = 1; j < M; ++j) {
      o[0][j] = 1;
      marked[0][j] = 1;
      Q.push(0);
      Q.push(j);
    }
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int y = Q.front();
      Q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !marked[nx][ny] &&
            mat[nx][ny] >= mat[x][y]) {
          o[nx][ny] = 1;
          marked[nx][ny] = 1;
          Q.push(nx);
          Q.push(ny);
        }
      }
    }
    marked.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
      s[i][M - 1] = 1;
      marked[i][M - 1] = 1;
      Q.push(i);
      Q.push(M - 1);
    }
    for (int j = 0; j < M - 1; ++j) {
      s[N - 1][j] = 1;
      marked[N - 1][j] = 1;
      Q.push(N - 1);
      Q.push(j);
    }
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int y = Q.front();
      Q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !marked[nx][ny] &&
            mat[nx][ny] >= mat[x][y]) {
          s[nx][ny] = 1;
          marked[nx][ny] = 1;
          Q.push(nx);
          Q.push(ny);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (o[i][j] && s[i][j])
          ++ans;
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }
    Solution ob;
    cout << ob.water_flow(mat, n, m) << endl;
  }
}

// } Driver Code Ends
