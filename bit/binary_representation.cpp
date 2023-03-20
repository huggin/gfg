//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  string getBinaryRep(int N) {
    // Write Your Code here
    string ans;
    while (N) {
      ans.push_back(N % 2 + '0');
      N /= 2;
    }
    while (ans.size() < 30) {
      ans.push_back('0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    string ans = ob.getBinaryRep(N);
    cout << ans << endl;
  }
  return 0;
}
// } Driver Code Ends
