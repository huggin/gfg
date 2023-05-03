//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  long long sumOfFifthPowers(long long N) {
    // code here
    long long ans = 0;
    for (long long i = 1; i <= N; ++i) {
      ans += i * i * i * i * i;
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
    cout << ob.sumOfFifthPowers(N) << "\n";
  }
}
// } Driver Code Ends
