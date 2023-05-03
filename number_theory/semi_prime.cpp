//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  int checkSemiprime(int N) {
    // code here
    int ans = 0;
    for (int i = 2; i * i <= N; ++i) {
      while (N % i == 0) {
        ans++;
        N /= i;
      }
    }
    if (N != 1)
      ++ans;
    return ans == 2 ? 1 : 0;
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
    cout << ob.checkSemiprime(N) << "\n";
  }
}
// } Driver Code Ends
