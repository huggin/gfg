//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  vector<int> largestSquare(vector<vector<int>> M, int R, int C, int K, int Q,
                            int q_i[], int q_j[]) {
    // code here
    vector<vector<int>> m(M);
    for (int i = 1; i < R; ++i) {
      m[i][0] += m[i - 1][0];
    }
    for (int i = 1; i < C; ++i) {
      m[0][i] += m[0][i - 1];
    }
    for (int i = 1; i < R; ++i) {
      for (int j = 1; j < C; ++j) {
        m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
      }
    }
    vector<int> res(Q);
    for (int i = 0; i < Q; ++i) {
      int x = q_i[i];
      int y = q_j[i];
      int dist = min(min(x, R - 1 - x), min(y, C - 1 - y));
      int ans = -1;
      int lo = 0, hi = dist;
      while (lo <= hi) {
        int mid = (hi - lo) / 2 + lo;
        int lx = x - mid, ly = y - mid;
        int rx = x + mid, ry = y + mid;
        int total = m[rx][ry];
        if (lx - 1 >= 0) {
          total -= m[lx - 1][ry];
        }
        if (ly - 1 >= 0) {
          total -= m[rx][ly - 1];
        }
        if (lx - 1 >= 0 && ly - 1 >= 0) {
          total += m[lx - 1][ly - 1];
        }
        if (total <= K) {
          ans = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      if (ans == -1)
        res[i] = 0;
      else
        res[i] = 2 * ans + 1;
    }
    return res;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int R, C, K, Q, x;
    cin >> R >> C;
    vector<vector<int>> M;

    for (int a = 0; a < R; a++) {
      vector<int> temp;
      for (int b = 0; b < C; b++) {
        cin >> x;
        temp.push_back(x);
      }
      M.push_back(temp);
    }

    cin >> K >> Q;

    int q_i[Q], q_j[Q];

    for (int i = 0; i < Q; i++)
      cin >> q_i[i];
    for (int i = 0; i < Q; i++)
      cin >> q_j[i];

    Solution ob;
    vector<int> res = ob.largestSquare(M, R, C, K, Q, q_i, q_j);

    for (int i = 0; i < Q; i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
