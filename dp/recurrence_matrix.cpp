//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  vector<int> CountOnes(vector<int> Queries) {
    // Code heret
    vector<int> C(100);
    C[0] = 0, C[1] = 0, C[2] = 1, C[3] = 1;
    // cout << "0011";
    for (int i = 4; i <= 100; ++i) {
      C[i] = (3 * C[i - 1] + 4 * C[i - 2] + 5 * C[i - 3] + 6 * C[i - 4]) % 2;
      // cout << C[i];
    }
    // cout << endl;
    // string s = "0011101";
    int s[] = {1, 0, 1, 0, 1, 0, 1};
    vector<int> dp(1001);
    dp[1] = 0;
    for (int i = 2; i <= 1000; ++i) {
      dp[i] = dp[i - 1];
      long long index = i * i * i % 7;
      for (int j = 1; j < i; ++j) {
        dp[i] += 2 * (s[index * j * j * j % 7]);
      }
      dp[i] += s[index * i * i * i % 7];
    }

    vector<int> ans;
    for (auto q : Queries) {
      ans.push_back(dp[q]);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int q;
    cin >> q;
    vector<int> Queries(q);
    for (int i = 0; i < q; i++) cin >> Queries[i];
    Solution obj;
    vector<int> ans = obj.CountOnes(Queries);
    for (auto i : ans) cout << i << "\n";
  }
  return 0;
}
// } Driver Code Ends
