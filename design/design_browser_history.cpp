//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class BrowserHistory {
  vector<string> history;
  int curr;

public:
  // constructor to initialize object with homepage
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    curr = 0;
  }

  // visit current url
  void visit(string url) {
    history.resize(curr + 1);
    history.push_back(url);
    curr = history.size() - 1;
  }

  // 'steps' move backward in history and return current page
  string back(int steps) {
    curr = max(0, curr - steps);
    return history[curr];
  }

  // 'steps' move forward and return current page
  string forward(int steps) {
    curr = min(int(history.size() - 1), curr + steps);
    return history[curr];
  }
};

//{ Driver Code Starts.

int main() {
  string homepage;
  cin >> homepage;

  BrowserHistory obj(homepage);

  int total_queries;
  cin >> total_queries;
  while (total_queries--) {
    int query;
    cin >> query;

    // if query = 1, visit()
    // if query = 2, back()
    // if query = 3, forward()

    if (query == 1) {
      string url;
      cin >> url;
      obj.visit(url);
    } else if (query == 2) {
      int steps;
      cin >> steps;
      cout << obj.back(steps) << endl;
    } else {
      int steps;
      cin >> steps;
      cout << obj.forward(steps) << endl;
    }
  }
  return 0;
}
// } Driver Code Ends
