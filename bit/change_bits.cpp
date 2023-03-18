//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  vector<int> changeBits(int N) {
    // code here
    int n = N;
    bool start = false;
    for (int i = 31; i >= 0; --i) {
      if (N & (1 << i)) start = true;
      if (start && (N ^ (1 << i))) n |= (1 << i);
    }
    return vector<int>{n - N, n};
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    auto ans = ob.changeBits(N);
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}
// } Driver Code Ends
