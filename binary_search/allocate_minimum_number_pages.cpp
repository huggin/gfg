//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  int ok(int k, int A[], int N, int M) {
    int t = 0;
    for (int i = 0; i < N; ++i) {
      if (A[i] > k) return 0;
    }
    int num = 0;
    for (int i = 0; i < N; ++i) {
      t = t + A[i];
      if (t > k) {
        ++num;
        t = A[i];
      }
    }
    ++num;
    if (num <= M) return 1;
    return 0;
  }

 public:
  // Function to find minimum number of pages.
  int findPages(int A[], int N, int M) {
    // code here
    if (M > N) return -1;
    long long lo = *max_element(A, A + N), hi = accumulate(A, A + N, 0LL);
    // cout << lo << ' ' << hi << endl;
    int ans = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (ok(mid, A, N, M)) {
        ans = mid;
        hi = mid - 1;
        // cout << mid << "ok" << endl;
      } else {
        // cout << mid << "not ok" << endl;
        lo = mid + 1;
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
    int m;
    cin >> m;
    Solution ob;
    cout << ob.findPages(A, n, m) << endl;
  }
  return 0;
}

// } Driver Code Ends
