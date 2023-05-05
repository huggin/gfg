//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  long long lucas(int n) {
    // code here.
    if (n == 0)
      return 2;
    if (n == 1)
      return 1;
    long long l0 = 2, l1 = 1;
    long long ans = 0;
    for (int i = 2; i <= n; ++i) {
      ans = (l0 + l1) % 1000000007;
      l0 = l1;
      l1 = ans;
    }
    return ans;
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
    cout << ob.lucas(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
