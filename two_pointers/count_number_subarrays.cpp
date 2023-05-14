//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  long long solve(const vector<int> &a, int n, long long x) {
    int i = 0, j = 0;
    long long total = 0;
    long long ans = 0;
    while (i < n) {
      total += a[i++];
      while (total > x) {
        total -= a[j++];
      }
      ans += i - j + 1;
    }
    return ans;
  }

public:
  long long countSubarray(int N, vector<int> A, long long L, long long R) {
    // code here
    return solve(A, N, R) - solve(A, N, L - 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    long long L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    Solution obj;
    auto ans = obj.countSubarray(N, A, L, R);
    cout << ans << endl;
  }
}
// } Driver Code Ends
