//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int fib(int N) {
    // code here
    if (N == 0)
      return 0;
    if (N == 1)
      return 1;
    int a = 0, b = 1;
    for (int i = 2; i <= N; ++i) {
      int t = a + b;
      a = b;
      b = t % 10;
    }
    return b;
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
    cout << ob.fib(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
