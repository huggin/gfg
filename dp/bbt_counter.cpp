//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  long long int countBT(int h) {
    // code here
    long long ans[h + 1];
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= h; ++i) {
      ans[i] =
          (ans[i - 1] * ans[i - 1] + 2 * ans[i - 2] * ans[i - 1]) % 1000000007;
    }
    return ans[h];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h;
    cin >> h;
    Solution ob;
    cout << ob.countBT(h) << endl;
  }
  return 0;
}

// } Driver Code Ends
