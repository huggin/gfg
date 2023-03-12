//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct A {
  A() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
  }
};

A a;

class Solution {
 public:
  vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    // code here
    long long a = 0;
    for (int i = 0; i < N; ++i) a ^= Arr[i];

    long long b = a & -a;
    long long x = 0, y = 0;
    for (int i = 0; i < N; ++i)
      if (Arr[i] & b)
        x ^= Arr[i];
      else
        y ^= Arr[i];

    if (x < y) swap(x, y);
    return {x, y};
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int N;
    cin >> N;
    long long int Arr[N];
    for (long int i = 0; i < N; i++) cin >> Arr[i];
    Solution ob;
    vector<long long int> ans = ob.twoOddNum(Arr, N);
    for (long long int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
