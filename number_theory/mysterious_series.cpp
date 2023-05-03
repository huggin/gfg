//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  long long nthMysterious(long long N) {
    // code here
    vector<long long> p;

    vector<bool> prime(10000, 1);
    prime[0] = prime[1] = 1;
    for (int i = 2; i < 10000; ++i) {
      if (prime[i]) {
        p.push_back(i);
        for (int j = i * i; j < 10000; j += i)
          prime[j] = 0;
      }
    }

    return p[N - 1] * p[N - 1] + 1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N;
    cin >> N;
    Solution ob;
    cout << ob.nthMysterious(N) << endl;
  }
  return 0;
}

// } Driver Code Ends
