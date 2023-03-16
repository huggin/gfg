//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int CountInterestingPrimeNo(int N) {
    // Code here.
    unordered_set<int> s;
    for (int i = 1; i * i * i * i <= N; ++i) {
      int a = i * i;
      a = a * a;
      for (int j = 1; j * j <= N; ++j) {
        int b = j * j;
        s.insert(a + b);
      }
    }

    int ans = 0;
    vector<int> p(N + 1, 1);
    p[0] = p[1] = 0;

    for (long long i = 2; i <= N; ++i) {
      if (p[i]) {
        if (s.find(i) != s.end()) ++ans;
        for (long long j = i * i; j <= N; j += i) p[j] = 0;
      }
    }

    return ans;
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
    int ans = ob.CountInterestingPrimeNo(N);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
