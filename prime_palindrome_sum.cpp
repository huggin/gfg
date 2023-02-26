//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  bool prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) return false;
    return true;
  }

  bool palindrome(int n) {
    string s = to_string(n);
    int m = s.size();
    for (int i = 0; i < m / 2; ++i)
      if (s[i] != s[m - 1 - i]) return false;
    return true;
  }

 public:
  long long getPPS(int a, int b) {
    // code here
    long long ans = 0;
    for (int i = a; i <= b; ++i) {
      if (prime(i) && palindrome(i)) ans += i;
    }
    return ans;
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
    cout << ob.getPPS(a, b) << endl;
  }
  return 0;
}
// } Driver Code Ends
