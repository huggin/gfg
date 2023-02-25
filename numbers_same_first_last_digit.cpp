//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int first(int n) {
    while (n >= 10) {
      n /= 10;
    }
    return n;
  }

 public:
  int numbersInRange(int L, int R) {
    // code here
    int ans = 0;

    for (int i = L; i <= R; ++i) {
      if (first(i) == i % 10) ++ans;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int L, R;
    cin >> L >> R;
    Solution ob;
    cout << ob.numbersInRange(L, R) << endl;
  }
  return 0;
}

// } Driver Code Ends
