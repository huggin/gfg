//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int repeatedSumOfDigits(int N) {
    // code here
    if (N < 10)
      return N;
    int n = 0;
    while (N) {
      n += N % 10;
      N /= 10;
    }
    return repeatedSumOfDigits(n);
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
    cout << ob.repeatedSumOfDigits(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
