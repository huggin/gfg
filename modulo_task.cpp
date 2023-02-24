//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  long long modTask(long long N) {
    // code here
    return N / 2 + 1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N;

    cin >> N;

    Solution ob;
    cout << ob.modTask(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
