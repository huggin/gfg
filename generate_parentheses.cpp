//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

// } Driver Code Ends
// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
  vector<string> ans;
  int N;
  void solve(int k, int left, int right, string& t) {
    if (k == N) {
      ans.push_back(t);
      return;
    }
    if (left - right > 0) {
      t.push_back(')');
      solve(k + 1, left, right + 1, t);
      t.pop_back();
    }
    if (left < N / 2) {
      t.push_back('(');
      solve(k + 1, left + 1, right, t);
      t.pop_back();
    }
  }

 public:
  vector<string> AllParenthesis(int n) {
    // Your code goes here
    ans.clear();
    string t;
    N = 2 * n;
    solve(0, 0, 0, t);
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
    Solution ob;
    vector<string> result = ob.AllParenthesis(n);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i) cout << result[i] << "\n";
  }
  return 0;
}

// } Driver Code Ends
