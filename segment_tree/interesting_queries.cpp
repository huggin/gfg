//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  vector<int> solveQueries(vector<int> nums, vector<vector<int>> Queries,
                           int k) {
    // Code here
    int n = nums.size();
    int nq = Queries.size();
    vector<int> ans(nq);
    int block_size = sqrt(n) + 1;
    vector<tuple<int, int, int>> query;

    for (int i = 0; i < nq; i++) {
      query.emplace_back(Queries[i][0] - 1, Queries[i][1] - 1, i);
    }

    sort(query.begin(), query.end(),
         [&](tuple<int, int, int> &a, tuple<int, int, int> &b) {
           int a_block = get<0>(a) / block_size;
           int b_block = get<0>(b) / block_size;
           if (a_block != b_block) {
             return a_block < b_block;
           }
           return get<1>(a) < get<1>(b);
         });

    int cl = 0, cr = -1, cnt = 0;
    unordered_map<int, int> freq;

    for (auto q : query) {
      int l = get<0>(q), r = get<1>(q);
      while (cl > l) {
        cl--;
        if (++freq[nums[cl]] == k) {
          cnt++;
        }
      }
      while (cr < r) {
        cr++;
        if (++freq[nums[cr]] == k) {
          cnt++;
        }
      }
      while (cl < l) {
        if (--freq[nums[cl]] == k - 1) {
          cnt--;
        }
        cl++;
      }
      while (cr > r) {
        if (--freq[nums[cr]] == k - 1) {
          cnt--;
        }
        cr--;
      }

      ans[get<2>(q)] = cnt;
    }

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    vector<vector<int>> Queries;
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      Queries.push_back({l, r});
    }
    Solution obj;
    vector<int> ans = obj.solveQueries(nums, Queries, k);
    for (auto i : ans)
      cout << i << "\n";
  }
  return 0;
}
// } Driver Code Ends
