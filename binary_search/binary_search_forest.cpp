//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int ok(int tree[], int n, int mid, int k) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += tree[i] - mid > 0 ? tree[i] - mid : 0;
    }
    return sum - k;
  }

 public:
  int find_height(int tree[], int n, int k) {
    // code here
    int lo = 0, hi = *max_element(tree, tree + n);
    int ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int diff = ok(tree, n, mid, k);
      if (diff == 0) {
        return mid;
      } else if (diff > 0) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
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
    int n, k;
    cin >> n;

    int tree[n];
    for (int i = 0; i < n; i++) cin >> tree[i];
    cin >> k;
    Solution ob;
    cout << ob.find_height(tree, n, k) << endl;
  }
  return 1;
}
// } Driver Code Ends
