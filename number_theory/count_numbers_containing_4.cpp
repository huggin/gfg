//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  int countNumberswith4(int N) {
    // code here
    int ans = 0;
    for (int i = 4; i <= N; ++i) {
      int k = i;
      while (k > 0) {
        if (k % 10 == 4) {
          ++ans;
          break;
        }
        k /= 10;
      }
    }
    return ans;
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
    cout << ob.countNumberswith4(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
