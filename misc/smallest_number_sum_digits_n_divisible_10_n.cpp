//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  string digitsNum(int N) {
    // Code here.
    string ans;
    int n = N;
    while (N) {
      if (N >= 9) {
        ans.push_back('9');
        N -= 9;
      } else {
        ans.push_back(N + '0');
        N = 0;
      }
    }
    reverse(ans.begin(), ans.end());
    ans += string(n, '0');
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Solution ob;
    string ans = ob.digitsNum(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
