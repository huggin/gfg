//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends
class Solution {
  vector<pair<int, int>> v;
  int n;
  int g[N][N];

  bool solve(int k) {
    if (k == n) {
      return true;
    }
    int i = v[k].first;
    int j = v[k].second;
    // cout << i << ' ' << j << endl;
    int used[N + 1] = {0};
    for (int in = 0; in < N; ++in) {
      if (g[i][in] != 0) used[g[i][in]]++;
      if (g[in][j] != 0) used[g[in][j]]++;
    }
    for (int in = i / 3 * 3; in < (i / 3 + 1) * 3; ++in) {
      for (int jn = j / 3 * 3; jn < (j / 3 + 1) * 3; ++jn) {
        if (g[in][jn] != 0) {
          used[g[in][jn]]++;
        }
      }
    }
    for (int l = 1; l <= 9; ++l) {
      if (used[l] == 0) {
        g[i][j] = l;
        if (solve(k + 1)) return true;
        g[i][j] = 0;
      }
    }
    return false;
  }

 public:
  // Function to find a solved Sudoku.
  bool SolveSudoku(int grid[N][N]) {
    // Your code here

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] = grid[i][j];
        if (grid[i][j] == 0) {
          v.emplace_back(i, j);
        }
      }
    }
    n = v.size();
    bool flag = solve(0);
    // cout << flag << endl;
    if (flag) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          grid[i][j] = g[i][j];
          // cout << g[i][i] << ' ';
        }
        // cout << '\n';
      }
    }
    return flag;
  }

  // Function to print grids of the Sudoku.
  void printGrid(int grid[N][N]) {
    // Your code here
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << grid[i][j] << ' ';
      }
    }
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int grid[N][N];

    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++) cin >> grid[i][j];

    Solution ob;

    if (ob.SolveSudoku(grid) == true)
      ob.printGrid(grid);
    else
      cout << "No solution exists";

    cout << endl;
  }

  return 0;
}
// } Driver Code Ends
