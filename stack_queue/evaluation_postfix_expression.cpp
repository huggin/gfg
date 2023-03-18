//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to evaluate a postfix expression.
  int evaluatePostfix(string S) {
    // Your code heret
    stack<int> s;
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == '+') {
        auto o2 = s.top();
        s.pop();
        auto o1 = s.top();
        s.pop();
        s.push(o1 + o2);
      } else if (S[i] == '-') {
        auto o2 = s.top();
        s.pop();
        auto o1 = s.top();
        s.pop();
        s.push(o1 - o2);
      } else if (S[i] == '*') {
        auto o2 = s.top();
        s.pop();
        auto o1 = s.top();
        s.pop();
        s.push(o1 * o2);
      } else if (S[i] == '/') {
        auto o2 = s.top();
        s.pop();
        auto o1 = s.top();
        s.pop();
        s.push(o1 / o2);
      } else {
        s.push(S[i] - '0');
      }
    }
    return s.top();
  }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
  int t;
  cin >> t;
  cin.ignore(INT_MAX, '\n');
  while (t--) {
    string S;
    cin >> S;
    Solution obj;

    cout << obj.evaluatePostfix(S) << endl;
  }
  return 0;
}

// } Driver Code Ends
