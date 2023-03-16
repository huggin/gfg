//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to return the minimum cost of connecting the ropes.
  long long minCost(long long arr[], long long n) {
    // Your code here
    multiset<long long> s(arr, arr + n);
    long long ans = 0;
    while (s.size() > 1) {
      auto a = s.begin();
      long long t1 = *a;
      s.erase(a);
      auto b = s.begin();
      long long t2 = *b;
      s.erase(b);
      // cout << t1 << ' ' << t2 << endl;
      s.insert(t1 + t2);
      ans += t1 + t2;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long i, a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution ob;
    cout << ob.minCost(a, n) << endl;
  }
  return 0;
}

// } Driver Code Ends
