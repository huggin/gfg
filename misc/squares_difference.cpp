//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
public:
  long long int squaresDiff(int N) {
    // code here
    long long a = 0, b = 0;
    for (int i = 1; i <= N; ++i) {
      a += i;
      b += i * i;
    }
    return a * a - b;
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
    cout << ob.squaresDiff(N) << endl;
  }
  return 0;
}

// } Driver Code Ends
