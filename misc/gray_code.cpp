//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int getGray(int n) {
    // code here
    return n ^ (n >> 1);
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
    cout << ob.getGray(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
