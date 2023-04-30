//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
  bool cmp(int a[], int b[], int n) {
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i])
        return false;
    }
    return true;
  }

public:
  int search(string pat, string txt) {
    // code here
    int cp[256] = {0};
    for (char c : pat) {
      ++cp[c];
    }
    int ct[256] = {0};
    int n = pat.size();
    for (int i = 0; i < n; ++i) {
      ++ct[txt[i]];
    }
    int ans = 0;
    if (cmp(cp, ct, 256))
      ++ans;
    for (int i = n; i < txt.size(); ++i) {
      ++ct[txt[i]];
      --ct[txt[i - n]];
      if (cmp(cp, ct, 256))
        ++ans;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string pat, txt;
    cin >> txt >> pat;
    Solution ob;
    auto ans = ob.search(pat, txt);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
