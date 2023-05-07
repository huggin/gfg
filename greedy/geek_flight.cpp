//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution {
public:
  vector<pair<int, int>> win(vector<int> &power, int n, vector<int> &Q, int q) {
    // Write your code here
    sort(power.begin(), power.end());
    vector<pair<int, int>> ans;
    for (int i = 0; i < q; ++i) {
      int t = 0;
      int m = 0;
      for (int j = 0; j < n; ++j) {
        if (Q[i] >= power[j]) {
          t += power[j];
          m++;
        } else {
          break;
        }
      }

      ans.emplace_back(m, t);
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> power(n);
    for (int i = 0; i < n; i++) {
      cin >> power[i];
    }
    int q;
    cin >> q;
    vector<int> Q(q);
    for (int i = 0; i < q; i++) {
      cin >> Q[i];
    }
    Solution ob;
    vector<pair<int, int>> ans = ob.win(power, n, Q, q);
    for (auto it : ans) {
      cout << it.first << " " << it.second << endl;
    }
  }
  return 0;
}

// } Driver Code Ends
