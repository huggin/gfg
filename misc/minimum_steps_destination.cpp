//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int minSteps(int D) {
    // code here
    if (D < 0)
      D = -D;
    int d = 1;
    int ans = 0;
    int total = 0;
    while (true) {
      total += d;
      if (total == D)
        return d;
      if (total > D) {
        // cout << total << ' ' << d << endl;
        if ((total - D) % 2 == 0) {
          return d;
        } else if (d % 2 == 0 || total - d + 1 == D) {
          return d + 1;
        } else {
          return d + 2;
        }
      }
      ++d;
    }

    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int D;
    cin >> D;

    Solution ob;
    cout << ob.minSteps(D) << "\n";
  }
  return 0;
}
// } Driver Code Ends
