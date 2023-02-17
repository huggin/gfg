//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  bool prime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

 public:
  int maxDigit(int L, int R) {
    // code here
    vector<int> cnt(10);
    for (int i = L; i <= R; ++i) {
      if (prime(i)) {
        // cout << i << endl;
        int n = i;
        while (n) {
          cnt[n % 10]++;
          n /= 10;
        }
      }
    }

    int ans = -1;
    int ma = 1;
    for (int i = 0; i < 10; ++i) {
      if (cnt[i] >= ma) {
        ma = cnt[i];
        ans = i;
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
    int L, R;
    cin >> L >> R;
    Solution ob;
    cout << ob.maxDigit(L, R) << endl;
  }
  return 0;
}

// } Driver Code Ends
