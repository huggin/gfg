//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  vector<int> findMaxRow(vector<vector<int>> mat, int N) {
    // code here
    int i = 0, j = N - 1;
    int row = 0;

    while (i < N && j >= 0) {
      if (mat[i][j] == 1) {
        --j;
        row = i;
      } else {
        ++i;
      }
    }
    return vector<int>{row, N - 1 - j};
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> arr[i][j];
    Solution obj;
    vector<int> ans = obj.findMaxRow(arr, n);
    for (int val : ans) {
      cout << val << " ";
    }
    cout << endl;
  }
}
// } Driver Code Ends
