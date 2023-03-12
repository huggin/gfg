//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int findMidSum(int ar1[], int ar2[], int n) {
    // code here
    if (n == 1) return ar1[0] + ar2[0];
    int l1 = 0, h1 = n - 1, l2 = 0, h2 = n - 1;
    while (l1 <= h1 && l2 <= h2) {
      if (l1 + 1 == h1 && l2 + 1 == h2) {
        return max(ar1[l1], ar2[l2]) + min(ar1[h1], ar2[h2]);
      }
      int m1 = l1 + (h1 - l1) / 2;
      int m2 = l2 + (h2 - l2) / 2;
      if ((h2 - l2) % 2 == 1) ++m2;

      if (ar1[m1] == ar2[m2]) return ar1[m1] + ar2[m2];
      if (ar1[m1] < ar2[m2]) {
        l1 = m1;
        h2 = m2;
      } else {
        h1 = m1;
        l2 = m2;
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    int ar1[n], ar2[n];
    for (i = 0; i < n; i++) {
      cin >> ar1[i];
    }
    for (i = 0; i < n; i++) {
      cin >> ar2[i];
    }
    Solution ob;
    auto ans = ob.findMidSum(ar1, ar2, n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
