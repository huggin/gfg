//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  vector<int> rotation(int n) {
    // Code Heree
    queue<int> q;
    for (int i = 0; i < n; ++i) q.push(i);

    vector<int> ans(n);
    int c = 1;
    while (c <= n) {
      for (int i = 0; i < c; ++i) {
        int t = q.front();
        q.pop();
        q.push(t);
      }
      int t = q.front();
      q.pop();
      ans[t] = c;
      ++c;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  Solution obj;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ans;
    ans = obj.rotation(n);
    for (int i : ans) cout << i << " ";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
