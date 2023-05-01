//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  bool ok(int h, const vector<int> &a, int M) {
    long long total = 0;
    for (auto c : a) {
      if (c > h) {
        total += c - h;
      }
    }
    return total >= M;
  }

public:
  int maxHeight(vector<int> &A, int M) {
    // Write your code here
    int hi = 0;
    for (int i = 0; i < A.size(); ++i) {
      hi = max(hi, A[i]);
    }
    int lo = 0;
    int ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      bool flag = ok(mid, A, M);
      // cout << mid << ' ' << flag << endl;
      if (flag) {
        ans = mid;
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
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    int M;
    cin >> M;
    Solution ob;
    int ans = ob.maxHeight(A, M);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends
