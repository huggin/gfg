//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  string captain(int N) {
    // code here
    return N % 3 ? "JELLY" : "JACK";
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
    cout << ob.captain(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
