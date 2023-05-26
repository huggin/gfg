//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node {
public:
  Node(int val = -1) : val(val) { children.resize(2, nullptr); }
  std::vector<Node *> children;
  int val;
};

class Solution {
  Node *root = nullptr;

  void put(int a) {
    Node *p = root;
    for (int i = 31; i >= 0; i--) {
      int d = (a >> i) & 1;
      if (p->children[d] == nullptr) {
        p->children[d] = new Node();
      }
      p = p->children[d];
    }
    p->val = a;
  }

  int get(int a) {
    Node *p = root;
    for (int i = 31; i >= 0; i--) {
      int d = (a >> i) & 1;
      if (p->children[1 - d] != nullptr) {
        p = p->children[1 - d];
      } else if (p->children[d] != nullptr) {
        p = p->children[d];
      } else {
        break;
      }
    }
    return p->val ^ a;
  }

public:
  vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                               vector<vector<int>> &queries) {
    // code here
    root = new Node();
    std::sort(arr.begin(), arr.end());

    std::vector<std::pair<std::pair<int, int>, int>> qi;
    for (int i = 0; i < Q; i++) {
      qi.push_back(
          std::make_pair(std::make_pair(queries[i][1], queries[i][0]), i));
    }
    std::sort(qi.begin(), qi.end());

    std::vector<long long> ans(Q, -1);
    for(int i=0, j = 0; j < Q; ++j) {
      while (i < N && arr[i] <= qi[j].first.first) {
        put(arr[i]);
        ++i;
      }
      if (i != 0) {
        ans[qi[j].second] = get(qi[j].first.second);
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
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> queries(Q, vector<int>(2));
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < Q; i++) {
      cin >> queries[i][0] >> queries[i][1];
    }
    Solution obj;
    vector<long long> ans = obj.maximumXor(N, Q, arr, queries);
    for (auto &it : ans)
      cout << it << ' ';
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
