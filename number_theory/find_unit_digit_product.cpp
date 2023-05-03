//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int binPow(int a, int b) {
    int ans = 1;
    while (b) {
      if (b & 1) {
        ans = (ans * a) % 10;
      }
      a = a * a % 10;
      b >>= 1;
    }
    return ans;
  }

public:
  int theLastDigit(int a, int b, int c, int d, int e, int f) {
    // code here
    a %= 10;
    c %= 10;
    e %= 10;
    int ans = 1;
    ans *= binPow(a, b);
    ans *= binPow(c, d) % 10;
    ans = ans * binPow(e, f) % 10;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    Solution ob;
    cout << ob.theLastDigit(a, b, c, d, e, f) << endl;
  }
  return 0;
}
// } Driver Code Ends
