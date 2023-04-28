//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // Function to return a list of integers denoting spiral traversal of matrix.
  vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
    // code here
    vector<int> ans(r * c);
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int lr = 0, hr = r - 1, lc = 0, hc = c - 1;
    int x = 0, y = 0;
    int k = 0;
    int d = 0;
    while (k < r * c) {
      ans[k++] = matrix[x][y];
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx > hr || nx < lr || ny > hc || ny < lc) {
        if (d == 0) {
          lr++;
        } else if (d == 1) {
          hc--;
        } else if (d == 2) {
          hr--;
        } else {
          lc++;
        }
        d = (d + 1) % 4;
        nx = x + dx[d];
        ny = y + dy[d];
      }
      x = nx;
      y = ny;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;

  while (t--) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r);

    for (int i = 0; i < r; i++) {
      matrix[i].assign(c, 0);
      for (int j = 0; j < c; j++) {
        cin >> matrix[i][j];
      }
    }

    Solution ob;
    vector<int> result = ob.spirallyTraverse(matrix, r, c);
    for (int i = 0; i < result.size(); ++i)
      cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
