//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  int count(const vector<int> &p) {
    int ans = 0;
    for (int i = 0; i < p.size(); ++i) {
      ans = ans * 10 + p[i];
    }
    return ans;
  }

public:
  vector<int> permutaion(int N) {
    // Code here
    vector<int> p;
    while (N) {
      p.push_back(N % 10);
      N /= 10;
    }

    int ans = 0;
    sort(p.begin(), p.end());
    int k = 0;
    do {
      ++k;
      ans += count(p);
    } while (next_permutation(p.begin(), p.end()));
    return vector<int>{k, ans};
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    Solution ob;
    vector<int> ans = ob.permutaion(N);
    for (auto i : ans)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
