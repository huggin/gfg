//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  long double NthTerm(int N) {
    // code here
    if (N == 1 || N == 2) return 2;
    long double ans = 2;
    int a = N / 2;
    if (N % 2 == 0) {
      ans = pow(2, pow(3, a - 1));
    } else {
      ans = pow(2, pow(2, a));
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
    cout << fixed << setprecision(0) << ob.NthTerm(N) << endl;
  }
  return 0;
}

// } Driver Code Ends
