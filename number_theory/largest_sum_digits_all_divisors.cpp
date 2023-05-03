//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int count(int n) {
    int cnt = 0;
    while (n) {
      cnt += n % 10;
      n /= 10;
    }
    return cnt;
  }

public:
  int getLargest(int n) {
    // code here
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        ans = max(ans, count(i));
        ans = max(ans, count(n / i));
      }
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
    cout << ob.getLargest(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
