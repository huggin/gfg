//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  pair<int, int> endPoints(vector<vector<int>> matrix) {
    // code here
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int n = matrix.size();
    int m = matrix[0].size();

    int dir = 1;
    int i = 0, j = 0;
    while (i >= 0 && i < n && j >= 0 && j < m) {
      if (matrix[i][j] == 0) {
        i += dx[dir];
        j += dy[dir];
      } else {
        matrix[i][j] = 0;
        dir = (dir + 1) % 4;
      }
    }
    return make_pair(i - dx[dir], j - dy[dir]);
  }
};

//{ Driver Code Starts.

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);
    vector<vector<int>> matrix(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> matrix[i][j];
      }
    }
    Solution obj;
    pair<int, int> p = obj.endPoints(matrix);

    cout << "(" << p.first << ", " << p.second << ")" << endl;
  }
  return 0;
}
// } Driver Code Ends
