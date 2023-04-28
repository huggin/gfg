//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Function to find out minimum steps Knight needs to reach target position.
  int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos,
                           int N) {
    // Code here
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int v[N + 1][N + 1] = {0};
    queue<int> Q;
    Q.push(KnightPos[0]);
    Q.push(KnightPos[1]);
    Q.push(0);
    v[KnightPos[0]][KnightPos[1]] = 1;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      int y = Q.front();
      Q.pop();
      int d = Q.front();
      Q.pop();
      if (x == TargetPos[0] && y == TargetPos[1])
        return d;
      for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && v[nx][ny] == 0) {
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
  int tc;
  cin >> tc;
  while (tc--) {
    vector<int> KnightPos(2);
    vector<int> TargetPos(2);
    int N;
    cin >> N;
    cin >> KnightPos[0] >> KnightPos[1];
    cin >> TargetPos[0] >> TargetPos[1];
    Solution obj;
    int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
