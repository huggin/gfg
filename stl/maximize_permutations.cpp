//{ Driver Code Starts
#include <bits/stdc++.h>

#include <string>
using namespace std;

// } Driver Code Ends
class Solution {
  int count(const vector<int>& p) {
    int ans = 0;
    for (int i = 0; i < p.size(); ++i) {
      ans = ans * 10 + p[i];
    }
    return ans;
  }

 public:
  int maxPerm(int N, int M) {
    // code here
    vector<int> p;

    while (N) {
      p.push_back(N % 10);
      N /= 10;
    }
    sort(p.begin(), p.end());

    int ans = -1;
    do {
      int n = count(p);
      if (n <= M) ans = n;
    } while (next_permutation(p.begin(), p.end()));

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M;
    cin >> N >> M;

    Solution ob;
    cout << ob.maxPerm(N, M) << endl;
  }
  return 0;
}
// } Driver Code Ends
