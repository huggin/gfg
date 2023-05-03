//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool prime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
      if (n % i == 0)
        return false;
    }
    return true;
  }

public:
  long long int largestPrimeFactor(int N) {
    // code here
    if (prime(N))
      return N;
    int ans = 0;
    for (int i = sqrt(N); i >= 2; --i) {
      if (N % i == 0) {
        if (prime(i))
          ans = max(ans, i);
        if (prime(N / i))
          ans = max(ans, N / i);
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
    int N;
    cin >> N;
    Solution ob;
    cout << ob.largestPrimeFactor(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
