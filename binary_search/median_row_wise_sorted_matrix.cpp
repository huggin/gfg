//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  int median(vector<vector<int>> &matrix, int R, int C) {
    // code here
    int lo = 1, hi = 2000;
    int total = R * C;
    int ans = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      int mi = 0, eq = 0;
      for (int i = 0; i < R; ++i) {
        auto it = equal_range(matrix[i].begin(), matrix[i].end(), mid);
        mi += it.first - matrix[i].begin();
        eq += it.second - it.first;
      }

      if (mi <= total / 2 && mi + eq > total / 2) {
        return mid;
      } else if (mi > total / 2) {
        hi = mid - 1;
      } else if (mi + eq <= total / 2) {
        lo = mid + 1;
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
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        cin >> matrix[i][j];
    Solution obj;
    cout << obj.median(matrix, r, c) << endl;
  }
  return 0;
}
// } Driver Code Ends
