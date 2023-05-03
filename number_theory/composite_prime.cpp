//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  void seive(vector<int> &p) {
    for (int i = 2; i * i < p.size(); ++i) {
      if (p[i] == 1) {
        for (int j = 2 * i; j < p.size(); j += i) {
          p[j] = 0;
        }
      }
    }
  }

public:
  int Count(int L, int R) {
    // Code here
    if (L == 1 && R == 1)
      return 0;
    if (L == 1)
      L = 2;
    vector<int> prime(R + 1, 1);
    seive(prime);
    int ans = 0;
    for (int i = L; i <= R; ++i) {
      // cout << i << ' ' << prime[i] << endl;
      if (prime[i])
        --ans;
      else
        ++ans;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int L, R;
    cin >> L >> R;
    Solution obj;
    int ans = obj.Count(L, R);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
