//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N) {
    // Write your code here
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());
    int ans = 0;
    int i = 0, j = 0;
    while (i < X.size() || j < Y.size()) {
      // cout << i << ' ' << j << ' ' << X[i] << ' ' << Y[j] << endl;;
      if (i == X.size()) {
        ans += Y[j++] * (i + 1);
        continue;
      }
      if (j == Y.size()) {
        ans += X[i++] * (j + 1);
        continue;
      }
      if (X[i] > Y[j]) {
        ans += X[i++] * (j + 1);
      } else if (X[i] < Y[j]) {
        ans += Y[j++] * (i + 1);
      } else {
        if (i > j) {
          ans += Y[j++] * (i + 1);
        } else {
          ans += X[i++] * (j + 1);
        }
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
    int m, n;
    cin >> m >> n;
    vector<int> X(m - 1), Y(n - 1);
    for (int i = 0; i < m - 1; i++) {
      cin >> X[i];
    }
    for (int i = 0; i < n - 1; i++) {
      cin >> Y[i];
    }
    Solution ob;
    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends
