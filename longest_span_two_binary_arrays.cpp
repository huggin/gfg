//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int longestCommonSum(bool arr1[], bool arr2[], int n) {
    // code here
    unordered_map<int, int> m;
    m[0] = -1;
    int total = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (arr1[i] == 1) ++total;
      if (arr2[i] == 1) --total;
      if (m.find(total) != m.end())
        ans = max(ans, i - m[total]);
      else
        m[total] = i;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    bool arr1[n], arr2[n];
    for (i = 0; i < n; i++) {
      cin >> arr1[i];
    }
    for (i = 0; i < n; i++) {
      cin >> arr2[i];
    }
    Solution ob;
    auto ans = ob.longestCommonSum(arr1, arr2, n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
