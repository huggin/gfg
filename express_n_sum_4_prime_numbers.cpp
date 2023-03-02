// Wrong tests
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  bool solve(int k, int n, const vector<int>& p, vector<int>& ans) {
    if (k == 4) {
      if (n == 0) return true;
      return false;
    }
    for (int i = 0; i < p.size(); ++i) {
      if (n >= p[i]) {
        ans.push_back(p[i]);
        if (solve(k + 1, n - p[i], p, ans)) return true;
        ans.pop_back();
      } else {
        break;
      }
    }
    return false;
  }

 public:
  vector<int> Express(int N) {
    // Code here
    if (N < 8) return vector<int>{-1};

    vector<char> p(N + 1, 1);
    p[0] = p[1] = 0;
    vector<int> prime;
    for (long long i = 2; i <= N; ++i) {
      if (p[i]) {
        prime.push_back(i);
        for (long long j = i * i; j <= N; j += i) {
          p[j] = 0;
        }
      }
    }

    vector<int> ans;
    if (solve(0, N, prime, ans)) return ans;
    return vector<int>{-1};
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    Solution ob;
    vector<int> ans = ob.Express(N);
    for (auto i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
