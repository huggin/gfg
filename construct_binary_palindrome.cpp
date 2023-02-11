//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  string binaryPalindrome(int n, int k) {
    // Complete the function
    string ans(n, '0');
    for (int i = 0; i < n; i += k) ans[i] = ans[n - i - 1] = '1';
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    Solution obj;
    cout << obj.binaryPalindrome(n, k) << endl;
  }
  return 0;
}

// } Driver Code Ends
