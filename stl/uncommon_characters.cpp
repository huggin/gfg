//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  string UncommonChars(string A, string B) {
    // code here
    string ans;
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(),
                             back_inserter(ans));
    if (ans.empty())
      return "-1";
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string A, B;
    cin >> A;
    cin >> B;
    Solution ob;
    cout << ob.UncommonChars(A, B);
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
