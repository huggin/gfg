//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int steppingNumbers(int n, int m) {
    // Code Here
    queue<int> Q;
    for (int i = 1; i <= 9; ++i) {
      Q.push(i);
    }

    int ans = 0;
    if (n == 0)
      ans = 1;
    while (!Q.empty()) {
      int curr = Q.front();
      Q.pop();
      if (curr >= n && curr <= m)
        ++ans;
      int last = curr % 10;
      if (last >= 1) {
        int d = curr * 10 + last - 1;
        if (d <= m)
          Q.push(d);
      }
      if (last < 9) {
        int d = curr * 10 + last + 1;
        if (d <= m)
          Q.push(d);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    Solution obj;
    int n, m;
    cin >> n >> m;
    cout << obj.steppingNumbers(n, m) << endl;
  }
  return 0;
}

// } Driver Code Ends
