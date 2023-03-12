//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int swapNibbles(int N) {
    // code here
    int a = N & 0x0f;
    int b = N & 0xf0;
    return (a << 4) | (b >> 4);
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
    cout << ob.swapNibbles(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
