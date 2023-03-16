//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
  vector<int> primeTwins(int L, int R) {
    // code here
    vector<bool> prime(R + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= R; ++i) {
      if (prime[i]) {
        for (int j = i * i; j <= R; j += i) {
          prime[j] = false;
        }
      }
    }
    for (int i = L; i <= R - 2; ++i) {
      if (prime[i] && prime[i + 2]) {
        return vector<int>{i, i + 2};
      }
    }
    return vector<int>{-1};
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int L, R;
    cin >> L >> R;
    Solution ob;
    vector<int> ans = ob.primeTwins(L, R);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
