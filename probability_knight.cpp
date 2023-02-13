//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int marked[101][101][101] = {0};
double dp[101][101][101] = {0};

class Solution {
 public:
  double findProb(int N, int start_x, int start_y, int steps) {
    // Code here
    memset(dp, 0, sizeof(dp));
    memset(marked, 0, sizeof(marked));
    dp[start_x][start_y][0] = 1.0;

    marked[start_x][start_y][0] = 1;
    int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    queue<pair<int, int>> Q;
    Q.emplace(start_x * N + start_y, 0);
    while (!Q.empty()) {
      auto tp = Q.front();
      Q.pop();
      int x = tp.first / N;
      int y = tp.first % N;
      int s = tp.second;
      if (s == steps) break;
      for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
          dp[nx][ny][s + 1] += dp[x][y][s] * 0.125;
          if (!marked[nx][ny][s + 1]) {
            marked[nx][ny][s + 1] = 1;
            Q.emplace(nx * N + ny, s + 1);
          }
        }
      }
    }
    double ans = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ans += dp[i][j][steps];
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N, start_x, start_y, steps;
    cin >> N >> start_x >> start_y >> steps;
    Solution ob;
    double ans = ob.findProb(N, start_x, start_y, steps);
    cout << fixed << setprecision(6) << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
