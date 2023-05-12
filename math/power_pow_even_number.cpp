//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long int sum_of_square_evenNumbers(long long int n) {
    // Code here
    long long ans = 0;
    for (int i = 2; i <= 2 * n; i += 2)
      ans += i * i;
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    Solution ob;
    long long int ans = ob.sum_of_square_evenNumbers(n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
