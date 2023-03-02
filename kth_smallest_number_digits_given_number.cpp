//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  string kthSmallestNumber(string num, int k) {
    // Code here
    // if(num=="0"){
    //    return "09";
    //}
    sort(num.begin(), num.end());
    if (num[0] == '0') {
      int i = 0;
      while (i < num.size() && num[i] == '0') ++i;
      if (i == num.size()) return num;
      num[0] = num[i];
      num[i] = '0';
    }
    while (--k > 0) {
      next_permutation(num.begin(), num.end());
    }
    return num;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    string num;
    cin >> num;
    int k;
    cin >> k;
    Solution ob;
    string ans = ob.kthSmallestNumber(num, k);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
