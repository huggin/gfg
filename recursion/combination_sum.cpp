//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  vector<vector<int>> ans;
  vector<int> v;
  void solve(vector<int> &A, int B, int k) {
    if (B == 0) {
      ans.push_back(v);
      return;
    }
    for (int i = k; i < A.size(); ++i) {
      if (B >= A[i]) {
        v.push_back(A[i]);
        solve(A, B - A[i], i);
        v.pop_back();
      } else {
        break;
      }
    }
  }

public:
  // Function to return a list of indexes denoting the required
  // combinations whose sum is equal to given number.
  vector<vector<int>> combinationSum(vector<int> &A, int B) {
    // Your code here
    ans.clear();
    v.clear();
    sort(A.begin(), A.end());
    auto it = unique(A.begin(), A.end());
    A.erase(it, A.end());
    solve(A, B, 0);
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
    vector<int> A;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      A.push_back(x);
    }
    int sum;
    cin >> sum;
    Solution ob;
    vector<vector<int>> result = ob.combinationSum(A, sum);
    if (result.size() == 0) {
      cout << "Empty";
    }
    for (int i = 0; i < result.size(); i++) {
      cout << '(';
      for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j];
        if (j < result[i].size() - 1)
          cout << " ";
      }
      cout << ")";
    }
    cout << "\n";
  }
}
// } Driver Code Ends
