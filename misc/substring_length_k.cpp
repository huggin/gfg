//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int countOfSubstrings(string S, int K) {
    // code here
    int c[26] = {0};
    for (int i = 0; i < K; ++i) {
      c[S[i] - 'a']++;
    }
    int ans = 0;
    if (count(c, c + 26, 0) == 27 - K)
      ++ans;
    for (int i = K; i < S.size(); ++i) {
      c[S[i - K] - 'a']--;
      c[S[i] - 'a']++;
      if (count(c, c + 26, 0) == 27 - K)
        ++ans;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    int K;
    cin >> S;
    cin >> K;

    Solution ob;
    cout << ob.countOfSubstrings(S, K) << endl;
  }
  return 0;
}
// } Driver Code Ends
