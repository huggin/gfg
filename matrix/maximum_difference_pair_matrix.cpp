//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int findMaxValue(vector<vector<int>> &mat, int N) {
    // Write your code here
    for (int i = 1; i < N; ++i) {
      mat[i][0] = min(mat[i][0], mat[i - 1][0]);
      mat[0][i] = min(mat[0][i], mat[0][i - 1]);
    }
    int ans = INT_MIN;
    for (int i = 1; i < N; ++i) {
      for (int j = 1; j < N; ++j) {
        ans = max(ans, mat[i][j] - mat[i - 1][j - 1]);
        mat[i][j] =
            min({mat[i][j], mat[i - 1][j], mat[i][j - 1], mat[i - 1][j - 1]});
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> mat[i][j];
      }
    }
    Solution ob;
    int ans = ob.findMaxValue(mat, n);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends
