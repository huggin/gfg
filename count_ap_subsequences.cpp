//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int n;

  int solve(int a[], int k, int diff) {
    int ans = 0;
    for (int i = k + 1; i < n; ++i) {
      if (a[i] - a[k] == diff) {
        ++ans;
        ans += solve(a, i, diff);
      }
    }
    return ans;
  }

 public:
  long long int count(int N, int A[]) {
    // code here
    n = N;
    int ans = N + 1;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        ++ans;
        ans += solve(A, j, A[j] - A[i]);
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
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];
    Solution ob;
    cout << ob.count(N, a) << endl;
  }
  return 0;
}
// } Driver Code Ends
