//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int evenlyDivides(int N) {
    // code here
    int ans = 0;
    int n = N;
    while (n > 0) {
      int r = n % 10;
      if (r != 0 && N % r == 0)
        ++ans;
      n /= 10;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    cout << ob.evenlyDivides(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
