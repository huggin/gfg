//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int rectangleCount(int A) {
    // code here
    int ans = 0;
    for (int i = 1; i * i <= A; ++i) {
      if (A % i == 0) {
        if (i % 2 == 1 || A / i % 2 == 1) ++ans;
      }
    }
    int k = sqrt(A);
    if (k * k == A && k % 2 == 0) ++ans;
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int A;
    cin >> A;

    Solution ob;
    cout << ob.rectangleCount(A) << "\n";
  }
  return 0;
}
// } Driver Code Ends
