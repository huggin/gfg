//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int isSphenicNo(int N) {
    // Code here
    int ans = 0;
    for (int i = 2; i <= N; ++i) {
      if (N % i == 0) {
        ++ans;
        N /= i;
        if (N % i == 0) return 0;
      }
    }
    return ans == 3 ? 1 : 0;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    Solution ob;
    int ans = ob.isSphenicNo(N);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
