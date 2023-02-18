//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  int sum(int n) {
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        if (i * i == n)
          ans += i;
        else
          ans += i + n / i;
      }
    }
    return ans;
  }

 public:
  int sumOfDivisors(int N) {
    // Write Your Code here
    int ans = 0;
    for (int i = 1; i * i <= N; ++i) {
      if (N % i == 0) {
        if (i * i == N)
          ans += sum(i);
        else
          ans += sum(i) + sum(N / i);
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
    int ans = ob.sumOfDivisors(N);
    cout << ans << endl;
  }
  return 0;
}
// } Driver Code Ends
