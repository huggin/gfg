//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int characterReplacement(string S, int K) {
    // code here
    int n = S.size();
    int i = 0, j = 0;
    int count[26] = {0};
    int ans = 0;
    while (i < n) {
      count[S[i] - 'A']++;
      int ma = *max_element(count, count + 26);
      if (ma + K >= i - j + 1) {
        ans = max(ans, i - j + 1);
      } else {
        while (ma + K < i - j + 1) {
          count[S[j] - 'A']--;
          ++j;
          ma = *max_element(count, count + 26);
        }
        ans = max(ans, i - j + 1);
      }
      ++i;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    int K;
    cin >> K;

    Solution obj;
    cout << obj.characterReplacement(S, K) << endl;
  }
  return 0;
}
// } Driver Code Ends
