//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  vector<long long> absDifOne(long long N) {
    // code here.
    queue<long long> Q;
    for (int i = 1; i <= 9; ++i) {
      Q.push(i);
    }
    vector<long long> ans;
    while (!Q.empty()) {
      long long curr = Q.front();
      Q.pop();
      int last_digit = curr % 10;
      if (last_digit > 0) {
        long long d = curr * 10 + last_digit - 1;
        if (d <= N) {
          ans.push_back(d);
          Q.push(d);
        }
      }
      if (last_digit < 9) {
        long long d = curr * 10 + last_digit + 1;
        if (d <= N) {
          ans.push_back(d);
          Q.push(d);
        }
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
    long long n;
    cin >> n;
    Solution ob;
    vector<long long> res = ob.absDifOne(n);
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
    if (res.size() == 0)
      cout << -1;
    cout << endl;
  }
}

// } Driver Code Ends
