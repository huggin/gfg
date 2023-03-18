//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int findPosition(int N) {
    // code here
    if (N == 0) return -1;
    if ((N & (N - 1)) != 0) return -1;
    for (int i = 0; i < 32; ++i) {
      if ((N & (1 << i)) != 0) {
        return i + 1;
      }
    }
    return -1;
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
    cout << ob.findPosition(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
