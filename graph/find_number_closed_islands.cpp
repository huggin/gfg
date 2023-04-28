//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int closedIslands(vector<vector<int>> &matrix, int N, int M) {
    // Code here
    queue<int> Q;
    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
      if (matrix[i][0] == 1) {
        Q.push(i);
        Q.push(0);
        v[i][0] = 1;
      }
      if (matrix[i][M - 1] == 1) {
        Q.push(i);
        Q.push(M - 1);
        v[i][M - 1] = 1;
      }
    }
    for (int i = 0; i < M; ++i) {
      if (matrix[0][i] == 1) {
        Q.push(0);
        Q.push(i);
        v[0][i] = 1;
      }
      if (matrix[N - 1][i] == 1) {
        Q.push(N - 1);
        Q.push(i);
        v[N - 1][i] = 1;
      }
    }
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int y = Q.front();
      Q.pop();
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !v[nx][ny] &&
            matrix[nx][ny] == 1) {
          v[nx][ny] = 1;
          Q.push(nx);
          Q.push(ny);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (v[i][j] == 0 && matrix[i][j] == 1) {
          ++ans;
          v[i][j] = 1;
          Q.push(i);
          Q.push(j);
          while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            int y = Q.front();
            Q.pop();
            for (int k = 0; k < 4; ++k) {
              int nx = x + dx[k];
              int ny = y + dy[k];
              if (nx >= 0 && nx < N && ny >= 0 && ny < M && !v[nx][ny] &&
                  matrix[nx][ny] == 1) {
                v[nx][ny] = 1;
                Q.push(nx);
                Q.push(ny);
              }
            }
          }
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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> matrix[i][j];

    Solution obj;
    int ans = obj.closedIslands(matrix, N, M);
    cout << ans << "\n";
  }

  return 0;
}

// } Driver Code Ends
