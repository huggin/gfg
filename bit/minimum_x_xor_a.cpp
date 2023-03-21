//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int one(int n) {
    int ans = 0;
    while (n) {
      ++ans;
      n &= n - 1;
    }
    return ans;
  }

public:
  int minVal(int a, int b) {
    // code here
    int nb = one(b);
    int na = one(a);
    if (na >= nb) {
      int ans = 0;
      for (int i = 31; i >= 0; --i) {
        if (a & (1 << i)) {
          if (nb-- <= 0)
            break;
          ans |= 1 << i;
        }
      }
      return ans;
    } else {
      int ans = 0;
      for (int i = 0; i < 31; ++i) {
        if (a & (1 << i)) {
          ans |= 1 << i;
        } else {
          if (nb > na) {
            --nb;
            ans |= 1 << i;
          }
        }
      }
      return ans;
    }
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    Solution ob;
    cout << ob.minVal(a, b);

    cout << "\n";
  }

  return 0;
}
// } Driver Code Ends
