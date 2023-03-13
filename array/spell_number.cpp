//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  long long differentWaysToSpell(string N) {
    // code here
    long long ans = 1;
    int prev = -1;
    int t = 1;
    for (char c : N) {
      if (prev != c) {
        ans *= pow(2, t - 1);
        t = 1;
      } else {
        ++t;
      }
      prev = c;
    }
    ans *= pow(2, t - 1);
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string N;

    cin >> N;

    Solution ob;
    cout << ob.differentWaysToSpell(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
