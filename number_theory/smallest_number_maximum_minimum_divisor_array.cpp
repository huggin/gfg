//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int getNum(int arr[], int N) {
    // code here
    auto mm = minmax_element(arr, arr + N);
    int a = *mm.first;
    int b = *mm.second;

    return a * b / __gcd(a, b);
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
    cout << ob.getNum(arr, N) << endl;
  }
  return 0;
}
// } Driver Code Ends
