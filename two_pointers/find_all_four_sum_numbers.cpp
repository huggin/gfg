//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  // arr[] : int input array of integers
  // k : the quadruple sum required
  vector<vector<int>> fourSum(vector<int> &arr, int k) {
    // Your code goes here
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i + 1; j < arr.size(); ++j) {
        int k1 = j + 1, k2 = arr.size() - 1;
        while (k1 < k2) {
          if (arr[i] + arr[j] + arr[k1] + arr[k2] == k) {
            ans.push_back(vector<int>{arr[i], arr[j], arr[k1], arr[k2]});
            ++k1;
            --k2;
          } else if (arr[i] + arr[j] + arr[k1] + arr[k2] < k) {
            ++k1;
          } else {
            --k2;
          }
        }
      }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, i;
    cin >> n >> k;
    vector<int> a(n);
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution ob;
    vector<vector<int>> ans = ob.fourSum(a, k);
    for (auto &v : ans) {
      for (int &u : v) {
        cout << u << " ";
      }
      cout << "$";
    }
    if (ans.empty()) {
      cout << -1;
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
