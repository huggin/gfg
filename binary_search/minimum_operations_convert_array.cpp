//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int minInsAndDel(int A[], int B[], int N, int M) {
    // code here
    vector<int> dp;
    for (int i = 0; i < N; ++i) {
      if (binary_search(B, B + M, A[i])) {
        if (dp.empty() || dp[dp.size() - 1] < A[i]) {
          dp.push_back(A[i]);
        } else {
          int j;
          for (j = dp.size() - 1; j >= 0 && dp[j] >= A[i]; --j)
            ;
          dp[j + 1] = A[i];
        }
      }
    }
    // cout << dp.size() << endl;
    return (N - dp.size()) + (M - dp.size());
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M;
    cin >> N >> M;

    int A[N], B[M];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    Solution ob;
    cout << ob.minInsAndDel(A, B, N, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
