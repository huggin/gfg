//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*  Function to calculate the longest consecutive ones
 *   N: given input to calculate the longest consecutive ones
 */
class Solution {
 public:
  int maxConsecutiveOnes(int N) {
    // code here
    int ans = 0;
    int c = 0;
    for (int i = 0; i < 32; ++i) {
      if ((N & (1 << i)) != 0) {
        ++c;
        ans = max(c, ans);
      } else {
        c = 0;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

// Driver Code
int main() {
  int t;
  cin >> t;  // testcases
  while (t--) {
    int n;
    cin >> n;  // input n
    Solution obj;
    // calling maxConsecutiveOnes() function
    cout << obj.maxConsecutiveOnes(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
