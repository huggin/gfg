//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

class Solution {
 public:
  vector<int> factorial(int N) {
    // code here
    cpp_int v = 1;
    for (int i = 1; i <= N; ++i) {
      v *= i;
    }
    cout << v;
    return vector<int>{};
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    vector<int> result = ob.factorial(N);
    for (int i = 0; i < result.size(); ++i) {
      cout << result[i];
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
