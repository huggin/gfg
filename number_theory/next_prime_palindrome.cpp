//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

  bool palindrome(int n) {
    string s = to_string(n);
    n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
  }

 public:
  int PrimePalindrome(int N) {
    // Code here
    if (N == 1 || N == 2) return 2;
    int i = N;
    if (N % 2 == 0) ++i;
    for (;; i += 2) {
      if (palindrome(i) && prime(i)) return i;
    }
    return -1;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    Solution obj;
    int ans = obj.PrimePalindrome(N);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
