//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  string getSmallest(long long N) {
    // code here
    if (N == 1) return "1";
    int cnt[10] = {0};
    for (long long i = 2; i <= N; ++i) {
      if (i >= 10) return "-1";
      while (N % i == 0) {
        cnt[i]++;
        N /= i;
      }
    }
    string ans;
    while (cnt[3] >= 2) {
      cnt[9]++;
      cnt[3] -= 2;
    }
    while (cnt[2] >= 3) {
      cnt[8]++;
      cnt[2] -= 3;
    }
    if (cnt[3] == 1 && cnt[2] > 0) {
      cnt[6]++;
      cnt[3]--;
      cnt[2]--;
    }
    while (cnt[2] >= 2) {
      cnt[4]++;
      cnt[2] -= 2;
    }
    for (int i = 0; i < 10; ++i) {
      if (cnt[i] == 0) continue;
      ans += string(cnt[i], '0' + i);
    }
    return ans;
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
    cout << ob.getSmallest(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
