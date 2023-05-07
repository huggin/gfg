//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long reversedBits(long long X) {
    // code here
    long long ans = 0;
    for (int i = 0; i < 32; ++i) {
      ans = ans * 2 + X % 2;
      X /= 2;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long X;

    cin >> X;

    Solution ob;
    cout << ob.reversedBits(X) << endl;
  }
  return 0;
}
// } Driver Code Ends
