//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                   pair<int, int> destination) {
    // code here
    int n = grid.size();
    int m = grid[0].size();

    if (grid[source.first][source.second] == 0 ||
        grid[destination.first][destination.second] == 0)
      return -1;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[source.first][source.second] = 0;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    queue<int> Q;
    Q.push(source.first);
    Q.push(source.second);

    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int y = Q.front();
      Q.pop();
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (grid[nx][ny] == 0 || dist[nx][ny] != -1)
          continue;

        dist[nx][ny] = dist[x][y] + 1;
        Q.push(nx);
        Q.push(ny);
      }
    }
    return dist[destination.first][destination.second];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    pair<int, int> source, destination;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;
    Solution obj;
    cout << obj.shortestPath(grid, source, destination) << endl;
  }
}

// } Driver Code Ends
