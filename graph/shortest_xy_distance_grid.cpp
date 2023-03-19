//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int shortestXYDist(vector<vector<char>> grid, int N, int M) {
    // code here
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<int> Q;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] == 'X') {
          dist[i][j] = 0;
          Q.push(i);
          Q.push(j);
          Q.push(0);
        }
      }
    }
    int ans = 2 * N;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    while (!Q.empty()) {
      int n = Q.size();
      for (int i = 0; i < n; ++i) {
        int x = Q.front();
        Q.pop();
        int y = Q.front();
        Q.pop();
        int d = Q.front();
        Q.pop();

        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (!(nx >= 0 && nx < N && ny >= 0 && ny < M))
            continue;

          if (grid[nx][ny] == 'Y')
            return d + 1;
          if (grid[nx][ny] == 'X')
            continue;
          if (dist[nx][ny] == -1) {
            dist[nx][ny] = d + 1;
            Q.push(nx);
            Q.push(ny);
            Q.push(d + 1);
          }
        }
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M;
    char ch;
    cin >> N >> M;

    vector<vector<char>> grid;

    for (int i = 0; i < N; i++) {
      vector<char> col;
      for (int i = 0; i < M; i++) {
        cin >> ch;
        col.push_back(ch);
      }
      grid.push_back(col);
    }

    Solution ob;
    cout << ob.shortestXYDist(grid, N, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
