//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int canReach(int A[], int N) {
    // code here
    int curr = 0;
    vector<int> dp(N);
    int ma = 0;
    while (true) {
      if (curr >= N - 1) {
        return 1;
      }
      int ma2 = 0;
      for (int i = curr; i <= ma; ++i) {
        ma2 = max(ma2, i + A[i]);
      }
      if (ma2 >= N - 1) {
        return 1;
      }
      if (ma2 > ma) {
        curr = ma + 1;
        ma = ma2;
      } else {
        return 0;
      }
    }
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;

    int A[N];

    for (int i = 0; i < N; i++) cin >> A[i];

    Solution ob;
    cout << ob.canReach(A, N) << endl;
  }
  return 0;
}
// } Driver Code Ends
