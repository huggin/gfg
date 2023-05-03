//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int fact(int k) {
    int ans = 0;
    while (k > 0) {
      ans += k / 5;
      k /= 5;
    }
    return ans;
  }

public:
  int countZeroes(int n) {
    // Code here
    int ans = 0;
    for (int i = 1;; ++i) {
      int d = fact(i);
      if (d == n)
        ++ans;
      if (d > n)
        break;
    }
    return ans;
  }
};

//{ Driver Code Starts.
// Driver code
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Solution obj;
    cout << obj.countZeroes(n);
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
