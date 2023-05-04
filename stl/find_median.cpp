//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int find_median(vector<int> v) {
    // Code here.
    sort(begin(v), end(v));
    if (v.size() % 2 == 0)
      return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
    return v[v.size() / 2];
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    Solution ob;
    int ans = ob.find_median(v);
    cout << ans << "\n";
  }
  return 0;
}

// } Driver Code Ends
