//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
  vector<int> sumOfProperDivisors(int arr[], int N) {
    // code here
    vector<int> ans(N, 1);
    for (int i = 0; i < N; ++i) {
      if (arr[i] == 1) {
        ans[i] = 0;
        continue;
      }

      for (int j = 2; j * j <= arr[i]; ++j) {
        if (arr[i] % j == 0) {
          ans[i] += j;
          if (j * j != arr[i])
            ans[i] += arr[i] / j;
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
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
      cin >> arr[i];
    Solution ob;
    vector<int> ans = ob.sumOfProperDivisors(arr, N);
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
