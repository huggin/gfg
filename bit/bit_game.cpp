//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int swapBitGame(long long N) {
    // code here
    int cnt = 0;
    while (N) {
      ++cnt;
      N &= N - 1;
    }
    return cnt % 2 ? 1 : 2;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N;
    cin >> N;
    Solution ob;
    cout << ob.swapBitGame(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
