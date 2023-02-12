//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  long long int NoOfChicks(int n) {
    // Code here
    vector<long long> ans(n + 1);
    ans[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (i > 6) {
        auto j = i;
        ans[i] = ans[i - 1];
        while (j - 6 > 0) {
          ans[i] -= ans[j - 6] - ans[j - 7];
          j -= 6;
        }
        ans[i] *= 3;
      } else {
        ans[i] = ans[i - 1] * 3;
      }
    }
    return ans[n];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    Solution obj;
    long long int ans = obj.NoOfChicks(N);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
