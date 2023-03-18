//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  using ll = long long;

 public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr) {
    // Code Here
    vector<ll> ans;
    vector<int> row(n), col(n);
    int m = n;
    for (auto& q : arr) {
      if (row[q[0] - 1] == 0) {
        row[q[0] - 1] = 1;
        --n;
      }
      if (col[q[1] - 1] == 0) {
        col[q[1] - 1] = 1;
        --m;
      }
      ans.push_back(n * m);
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
    vector<vector<int>> arr(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      arr[i][0] = x;
      arr[i][1] = y;
    }
    Solution ob;
    vector<long long int> ans = ob.countZero(n, k, arr);

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }

  return 0;
}

// } Driver Code Ends
