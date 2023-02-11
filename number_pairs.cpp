//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // X[], Y[]: input arrau
  // M, N: size of arrays X[] and Y[] respectively
  // Function to count number of pairs such that x^y is greater than y^x.
  long long countPairs(int X[], int Y[], int M, int N) {
    // Your code here
    sort(Y, Y + N);
    long long y1 = count(Y, Y + N, 1);
    long long x1 = M - count(X, X + M, 1);
    long long ans = x1 * y1;
    // cout << ans << endl;
    long long tx = count(X, X + M, 3);
    long long ty = count(Y, Y + N, 2);
    ans += tx * ty;
    // cout << ans << endl;
    for (int i = 0; i < M; ++i) {
      if (X[i] == 1) continue;

      auto c = upper_bound(Y, Y + N, X[i]);
      if (X[i] == 2) {
        c = upper_bound(Y, Y + N, 4);
      }
      ans += Y + N - c;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int M, N;
    cin >> M >> N;
    int i, a[M], b[N];
    for (i = 0; i < M; i++) {
      cin >> a[i];
    }
    for (i = 0; i < N; i++) {
      cin >> b[i];
    }
    Solution ob;
    cout << ob.countPairs(a, b, M, N) << endl;
  }
}
// } Driver Code Ends
