//{ Driver Code Starts
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int maxSubsequenceSubstring(string x, string y, int n, int m);

// Driver Program
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string x, y;
    cin >> n >> m;
    cin >> x >> y;
    cout << maxSubsequenceSubstring(x, y, n, m) << "\n";
  }
  return 0;
}
// } Driver Code Ends

int maxSubsequenceSubstring(string X, string Y, int N, int M) {
  // code
  int ans = 0;
  for (int i = 0; i < M; ++i) {
    int cnt = 0;
    int k = i;
    for (int j = 0; j < N; ++j) {
      if (X[j] == Y[k]) {
        ++cnt;
        ++k;
      }
      ans = max(ans, cnt);
    }
  }
  return ans;
}
