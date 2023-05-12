//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
public:
  // You need to complete this function

  int ans;

  void solve(int N, int from, int to, int aux) {
    if (N == 1) {
      cout << "move disk 1 from rod " << from << " to rod " << to << '\n';
      ++ans;
      // cout << ans << endl;
      return;
    }
    solve(N - 1, from, aux, to);
    cout << "move disk " << N << " from rod " << from << " to rod " << to
         << '\n';
    ++ans;
    // cout << ans << endl;
    solve(N - 1, aux, to, from);
  }

  // avoid space at the starting of the string in "move disk....."
  long long toh(int N, int from, int to, int aux) {
    // Your code here
    ans = 0;
    solve(N, from, to, aux);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int T;
  cin >> T; // testcases
  while (T--) {
    int N;
    cin >> N; // taking input N

    // calling toh() function
    Solution ob;

    cout << ob.toh(N, 1, 3, 2) << endl;
  }
  return 0;
}

// Position this line where user code will be pasted.
//  } Driver Code Ends
