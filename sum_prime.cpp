//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool prime(int n) {
    if (n == 2) return true;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) return false;
    }
    return true;
  }

 public:
  vector<int> getPrimes(int N) {
    // code here
    vector<int> ans(2, -1);
    for (int i = 2; i <= N / 2; ++i) {
      if (prime(i) && prime(N - i)) {
        if (ans[0] == -1 || i < ans[0]) {
          ans[0] = i;
          ans[1] = N - i;
        }
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
    vector<int> ptr = ob.getPrimes(N);
    cout << ptr[0] << " " << ptr[1] << endl;
  }
  return 0;
}
// } Driver Code Ends
