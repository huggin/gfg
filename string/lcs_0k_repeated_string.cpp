//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int lcsK(int k, string st) {
    // code here
    int n = st.size();
    if (st.find('1') == string::npos) {
      return n * k;
    }
    int pre = 0, suf = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (st[i] == '1') {
        pre = ans;
        break;
      } else {
        ans++;
      }
    }
    ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (st[i] == '1') {
        suf = ans;
        break;
      } else {
        ans++;
      }
    }

    ans = 0;
    int ans2 = pre + suf;
    if (k == 1) ans2 = max(pre, suf);
    for (int i = pre; i + suf < n; ++i) {
      if (st[i] == '1') {
        ans2 = max(ans, ans2);
        ans = 0;
      } else {
        ++ans;
      }
    }
    return ans2;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    string st;
    cin >> st;

    Solution ob;
    cout << ob.lcsK(k, st) << "\n";
  }
  return 0;
}
// } Driver Code Ends
