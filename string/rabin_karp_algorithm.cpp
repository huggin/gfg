//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  vector<int> search(string pat, string txt) {
    // code here.
    vector<int> ans;
    int M = pat.size();
    int N = txt.size();
    int R = 256;
    const int Q = 1000007;
    int RM = 1;
    for (int i = 1; i <= M - 1; ++i) {
      RM = (R * RM) % Q;
    }
    int h = 0;
    for (int i = 0; i < M; ++i) {
      h = (R * h + pat[i]) % Q;
    }
    int th = 0;
    for (int i = 0; i < M; ++i) {
      th = (R * th + txt[i]) % Q;
    }
    if (h == th)
      ans.push_back(1);
    // cout << "th = " << th << endl;
    for (int i = M; i < N; i++) {
      th = (th + Q - (RM * txt[i - M]) % Q) % Q;
      th = (th * R + txt[i]) % Q;
      // cout << th << ' ' << h << endl;
      if (h == th)
        ans.push_back(i - M + 2);
    }
    if (ans.size() == 0)
      return vector<int>{-1};
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S, pat;
    cin >> S >> pat;
    Solution ob;
    vector<int> res = ob.search(pat, S);
    for (int i : res)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
