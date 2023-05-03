//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  int rightmostNonZeroDigit(int N, int A[]) {
    // code here
    int ans = 1;
    int two = 0, five = 0;
    for (int i = 0; i < N; ++i) {
      if (A[i] == 0)
        return -1;
      while (A[i] % 5 == 0) {
        ++five;
        A[i] /= 5;
      }
      while (A[i] % 2 == 0) {
        ++two;
        A[i] /= 2;
      }
      ans = (A[i] * ans) % 10;
    }
    if (five > two)
      return 5;
    for (int i = 0; i < two - five; ++i) {
      ans = (ans * 2) % 10;
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
    int A[n];
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    Solution ob;
    cout << ob.rightmostNonZeroDigit(n, A) << endl;
  }
  return 0;
}
// } Driver Code Ends
