//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  vector<vector<int>> M;
  int N;
  int K;

public:
  int selectKcities(int n, int k, vector<vector<int>> &mat) {
    // code here
    M = mat;
    N = n;
    K = k;

    int ans = INT_MAX;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> atm;
      for (int j = 0; j < n; ++j) {
        if ((i & (1 << j)) != 0) {
          atm.push_back(j);
        }
      }
      if (atm.size() != k)
        continue;
      int temp2 = 0;
      for (int j = 0; j < n; ++j) {
        int temp = INT_MAX;
        for (int l = 0; l < k; ++l) {
          temp = min(temp, mat[j][atm[l]]);
        }
        temp2 = max(temp2, temp);
      }
      ans = min(ans, temp2);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> mat[i][j];
      }
    }

    Solution obj;
    int ans = obj.selectKcities(n, k, mat);

    cout << ans << endl;
  }
}
// } Driver Code Ends
