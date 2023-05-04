//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  string prevPermutation(string s) {
    // code here
    if (prev_permutation(s.begin(), s.end()))
      return s;
    return "None";
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.prevPermutation(s) << endl;
  }
  return 0;
}

// } Driver Code Ends
