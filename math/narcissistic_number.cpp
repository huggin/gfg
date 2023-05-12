//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int isNarcissistic(int N) {
    // code here
    int n = 0;
    int t = N;
    while (t > 0) {
      ++n;
      t /= 10;
    }
    t = N;
    int ans = 0;
    while (t > 0) {
      int d = t % 10;
      ans += pow(d, n);
      t /= 10;
    }
    return ans == N;
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
    cout << ob.isNarcissistic(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
