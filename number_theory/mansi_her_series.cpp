//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  vector<int> prime;

  void sieve() {
    const int M = 100000;
    vector<char> is(M + 1, 1);
    is[0] = is[1] = 0;
    for (long long i = 2; i <= M; ++i) {
      if (is[i]) {
        prime.push_back(i);
        for (long long j = i * i; j <= M; j += i) {
          is[j] = 0;
        }
      }
    }
  }

public:
  int nthTerm(int n) {
    // code here
    sieve();
    cout << prime.size() << endl;
    // return n * (prime[n-1] + 1);
    return 0;
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
    cout << ob.nthTerm(n) << endl;
  }
  return 0;
}

// } Driver Code Ends
