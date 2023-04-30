//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++
class Solution {
public:
  string ReFormatString(string S, int K) {
    reverse(S.begin(), S.end());
    string ans;
    ans.reserve(S.size());
    int k = 0;
    for (auto c : S) {
      if (c == '-')
        continue;
      if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z') {
        ans.push_back(c);
      } else {
        ans.push_back(c - 'a' + 'A');
      }
      ++k;
      if (k % K == 0) {
        ans.push_back('-');
      }
    }
    if (ans[ans.size() - 1] == '-') {
      ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    int K;
    cin >> K;
    Solution ob;
    string ans = ob.ReFormatString(S, K);
    cout << ans;
    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
