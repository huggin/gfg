//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  int factorProduct(int N) {
    // code here
    const int M = 1e9 + 7;
    long long ans = 1;
    for (int i = 1; i * i <= N; ++i) {
      if (N % i == 0) {
        ans = ans * i % M;
        if (i * i != N)
          ans = ans * (N / i) % M;
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
    cout << ob.factorProduct(N) << "\n";
  }
}
// } Driver Code Ends
