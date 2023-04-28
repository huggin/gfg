//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
    // code here
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    if (A[0][0] == 0)
      return -1;
    queue<int> Q;
    Q.push(0);
    Q.push(0);
    Q.push(0);
    vector<vector<int>> v(N, vector<int>(M));
    v[0][0] = 1;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int y = Q.front();
      Q.pop();
      int d = Q.front();
      Q.pop();
      if (x == X && y == Y)
        return d;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && v[nx][ny] == 0 &&
            A[nx][ny] == 1) {
          v[nx][ny] = 1;
          Q.push(nx);
          Q.push(ny);
          Q.push(d + 1);
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
    int N, M, x, y;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> v[i][j];
    cin >> x >> y;
    Solution ob;
    cout << ob.shortestDistance(N, M, v, x, y) << "\n";
  }
}
// } Driver Code Ends
