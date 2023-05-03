//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int DivisibleByEight(string S) {
    // code here
    int n = 0;
    int m = S.size();
    for (int i = max(0, m - 3); i < m; ++i) {
      n = n * 10 + S[i] - '0';
    }
    return n % 8 == 0 ? 1 : -1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    Solution ob;
    cout << ob.DivisibleByEight(S) << "\n";
  }
}
// } Driver Code Ends
