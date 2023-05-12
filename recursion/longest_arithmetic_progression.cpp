//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  int solve(int a[], int i, int j, int n) {
    int diff = a[j] - a[i];
    int ans2 = 2;
    while (binary_search(a, a + n, a[j] + diff)) {
      // cout << i << ' ' << j << ' ' << diff << endl;
      ++ans2;
      diff += a[j] - a[i];
    }
    return ans2;
  }

public:
  int lengthOfLongestAP(int A[], int n) {
    // code here
    if (n <= 2)
      return n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        ans = max(ans, solve(A, i, j, n));
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
    int A[n];
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    Solution ob;
    auto ans = ob.lengthOfLongestAP(A, n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
