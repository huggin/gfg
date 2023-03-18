//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  void shortest_distance(vector<vector<int>>& m) {
    // Code here
    for (int k = 0; k < m.size(); ++k) {
      for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m.size(); ++j) {
          if (m[i][k] == -1 || m[k][j] == -1) {
            continue;
          } else {
            if (m[i][j] == -1 || m[i][k] + m[k][j] < m[i][j]) {
              m[i][j] = m[i][k] + m[k][j];
            }
          }
        }
      }
    }
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix[i][j];
      }
    }
    Solution obj;
    obj.shortest_distance(matrix);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
// } Driver Code Ends
