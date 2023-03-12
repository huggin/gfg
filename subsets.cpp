//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  vector<vector<int>> ans;

  void solve(int k, const vector<int>& A, vector<int>& t) {
    if (k == A.size()) {
      ans.push_back(t);
      return;
    }

    t.push_back(A[k]);
    solve(k + 1, A, t);
    t.pop_back();
    solve(k + 1, A, t);
  }

 public:
  vector<vector<int>> subsets(vector<int>& A) {
    // code here
    ans.clear();
    vector<int> t;
    solve(0, A, t);
    sort(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n;

    vector<int> array;
    for (int i = 0; i < n; i++) {
      cin >> x;
      array.push_back(x);
    }

    Solution ob;
    vector<vector<int>> res = ob.subsets(array);

    // Print result
    for (int i = 0; i < res.size(); i++) {
      for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
      cout << endl;
    }
  }

  return 0;
}
// } Driver Code Ends
