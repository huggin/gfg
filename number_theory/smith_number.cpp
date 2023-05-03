//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int sumOfDigits(int n) {
    int ans = 0;
    while (n) {
      ans += n % 10;
      n /= 10;
    }
    return ans;
  }

  int factor(int n) {
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      while (n % i == 0) {
        ans += sumOfDigits(i);
        n /= i;
      }
    }
    return ans;
  }

  bool prime(int n) {
    if (n == 0 || n == 1)
      return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

public:
  int smithNum(int n) {
    // code here
    if (prime(n))
      return 0;

    int a = sumOfDigits(n);
    int b = factor(n);

    return a == b ? 1 : 0;
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
    cout << ob.smithNum(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
