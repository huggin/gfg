//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  string removeConsecutiveCharacter(string S) {
    // code here.
    auto it = unique(S.begin(), S.end());
    S.erase(it, S.end());
    return S;
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
    cout << ob.removeConsecutiveCharacter(s) << endl;
  }
}

// } Driver Code Ends
