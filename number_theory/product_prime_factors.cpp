//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long int primeProduct(int N) {
    // code here
    long long ans = 1;
    for (int i = 2; i <= N; ++i) {
      if (N % i == 0) {
        ans *= i;
        while (N % i == 0)
          N /= i;
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
    cout << ob.primeProduct(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
