//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int sumOfDigits(int N) {
    // code here
    int ans = 0;
    while (N) {
      ans += N % 10;
      N /= 10;
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
    cout << ob.sumOfDigits(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
