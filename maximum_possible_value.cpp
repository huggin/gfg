//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  long long maxPossibleValue(int N, vector<int> A, vector<int> B) {
    // code here
    long long ans = 0;
    long long sticks = 0;
    int mi = INT_MAX;
    for (int i = 0; i < N; ++i) {
      int t = B[i] / 2;
      sticks += t * 2;
      ans += t * 2 * A[i];
      if (t > 0 && mi > A[i]) {
        mi = A[i];
      }
    }
    if (sticks % 4 == 0) return ans;
    return ans - 2 * mi;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }
    Solution obj;
    auto ans = obj.maxPossibleValue(N, A, B);
    cout << ans << endl;
  }
}
// } Driver Code Ends
