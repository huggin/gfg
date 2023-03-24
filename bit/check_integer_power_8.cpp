//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  string is_power_of_eight(long long int n) {
    // Code here.
    while (n != 1) {
      // cout << n << endl;
      if ((n & ~0x7) != n)
        return "No";
      n >>= 3;
    }
    return "Yes";
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    Solution ob;
    string ans = ob.is_power_of_eight(n);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
