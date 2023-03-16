//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  vector<int> orderedPrime(int n) {
    // code here
    vector<int> order(n + 1);
    for (int i = 2; i <= n; ++i) {
      while (n % i == 0) {
        order[i]++;
        n /= i;
      }
    }
    vector<int> ans;
    int t = 1;
    for (int i = 1; i < order.size(); ++i) {
      if (order[i]) {
        ans.push_back(order[i]);
        t *= order[i] + 1;
      }
    }

    sort(ans.begin(), ans.end());
    ans.push_back(t);

    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    Solution ob;
    vector<int> ans = ob.orderedPrime(n);
    for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << " ";
    cout << endl;
    cout << ans[ans.size() - 1] << "\n";
  }
  return 0;
}
// } Driver Code Ends
