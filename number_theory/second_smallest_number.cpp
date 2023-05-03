//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  string secondSmallest(int S, int D) {
    // code here
    if (D == 1)
      return "-1";
    if (D * 9 <= S)
      return "-1";
    string ans;
    int first = S - (D - 1) * 9;
    if (first <= 0)
      first = 1;
    ans.push_back('0' + first);
    S -= first;
    D--;
    while (S > 0) {
      int d = S - (D - 1) * 9;
      if (d < 0)
        d = 0;
      ans.push_back('0' + d);
      S -= d;
      D--;
    }
    if (ans[ans.size() - 1] == '0')
      return "-1";

    int k = ans.size() - 1;
    while (k >= 0 && ans[k] == '9')
      --k;

    if (k < 0)
      return "-1";
    if (k == ans.size() - 1) {
      ans[k]--;
      ans[k - 1]++;
    } else {
      ans[k + 1]--;
      ans[k]++;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int S, D;
    cin >> S >> D;
    Solution ob;
    cout << ob.secondSmallest(S, D) << endl;
  }
  return 0;
}
// } Driver Code Ends
