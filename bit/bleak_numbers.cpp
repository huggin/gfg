//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int countBits(int n) {
    int ans = 0;
    while (n) {
      ++ans;
      n &= n - 1;
    }
    return ans;
  }

public:
  int is_bleak(int n) {
    // Code here.
    for (int i = 1; i < n; ++i) {
      if (n == i + countBits(i))
        return 0;
    }
    return 1;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    Solution ob;
    int ans = ob.is_bleak(n);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
