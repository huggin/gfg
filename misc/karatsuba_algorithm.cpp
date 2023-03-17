//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  long long get(const string& a) {
    long long ans = 0;
    for (int i = 0; i < a.size(); ++i) ans = ans * 2 + (a[i] - '0');
    return ans;
  }

 public:
  long long karatsubaAlgo(string A, string B) {
    // code here
    long long a = get(A);
    long long b = get(B);
    // cout << a << ' ' << b << endl;
    return a * b;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string A, B;

    cin >> A >> B;

    Solution ob;
    cout << ob.karatsubaAlgo(A, B) << endl;
  }
  return 0;
}
// } Driver Code Ends
