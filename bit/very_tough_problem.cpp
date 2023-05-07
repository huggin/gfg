//{ Driver Code Starts

#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  string toughProblem(int n, int s, int x) {
    // Code Here
    if (s < x || (s - x) % 2)
      return "No";

    if (n == 1)
      return s == x ? "Yes" : "No";
    if (n >= 3)
      return "Yes";

    int j = (s - x) / 2;
    for (int i = 30; i >= 0; --i) {
      if (j & (1 << i)) {
        if (x & (1 << i))
          return "No";
      }
    }
    return "Yes";
  }
};

//{ Driver Code Starts.

int main() {
  Solution ob;
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, s, x;
    scanf("%d %d %d", &n, &s, &x);

    cout << ob.toughProblem(n, s, x) << endl;
  }
  return 0;
}
// } Driver Code Ends
