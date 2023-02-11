//{ Driver Code Starts
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  vector<int> bit;

  int sum(int idx, int n) {
    int ans = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
      ans += bit[idx];
    }
    return ans;
  }

  void update(int idx, int n, int value) {
    for (++idx; idx < n; idx += idx & -idx) {
      bit[idx] += value;
    }
  }

 public:
  vector<int> constructLowerArray(int *arr, int n) {
    // code here
    bit.assign(n + 1, 0);

    vector<int> a(arr, arr + n);
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
      arr[i] = lower_bound(a.begin(), a.end(), arr[i]) - a.begin() + 1;
    }

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
      ans[i] = sum(arr[i] - 1, n + 1);
      update(arr[i], n + 1, 1);
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
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.constructLowerArray(arr, n);
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
