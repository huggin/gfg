//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  vector<int> sumClosest(vector<int> arr, int x) {
    // code here
    vector<int> ans(2);
    int diff = INT_MAX;
    for (int i = 0, j = arr.size() - 1; i < j;) {
      int t = arr[i] + arr[j];
      if (abs(t - x) < diff) {
        diff = abs(t - x);
        ans[0] = arr[i];
        ans[1] = arr[j];
      }
      if (t < x) {
        ++i;
      } else if (t > x) {
        --j;
      } else {
        return ans;
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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.sumClosest(arr, x);
    cout << ans[0] << " " << ans[1] << "\n";
  }
  return 0;
}
// } Driver Code Ends
