//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int minSteps(int A[], int N, int K) {
    // code here
    sort(A, A + N);
    int sum[N] = {0};
    sum[0] = A[0];
    for (int i = 1; i < N; ++i) {
      sum[i] = sum[i - 1] + A[i];
    }
    int ans = INT_MAX;
    int ma = A[N - 1];
    for (int i = 0; i <= ma; ++i) {
      int k1 = lower_bound(A, A + N, i) - A - 1;
      int k2 = upper_bound(A, A + N, i + K) - A;
      int temp = sum[N - 1] - sum[k2 - 1] - (N - k2) * (i + K);
      if (k1 >= 0) temp += sum[k1];
      ans = min(ans, temp);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;

    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    Solution ob;
    cout << ob.minSteps(A, N, K) << endl;
  }
  return 0;
}
// } Driver Code Ends
