//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  vector<vector<int>> ans;

  void solve(const vector<int> &a, int k, vector<int> &vi) {
    if (k == a.size()) {
      ans.push_back(vi);
      sort(ans[ans.size() - 1].begin(), ans[ans.size() - 1].end());
      return;
    }
    solve(a, k + 1, vi);
    vi.push_back(a[k]);
    solve(a, k + 1, vi);
    vi.pop_back();
  }

public:
  // Function to find all possible unique subsets.
  vector<vector<int>> AllSubsets(vector<int> arr, int n) {
    // code here
    vector<int> vi;
    solve(arr, 0, vi);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
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
    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      A.push_back(x);
    }
    Solution obj;
    vector<vector<int>> result = obj.AllSubsets(A, n);
    // printing the output
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
