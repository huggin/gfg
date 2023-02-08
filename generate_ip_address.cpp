//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    vector<string> ans;
    void go(int k, string s, vector<int>& t) {
        if (k == 4 && s.empty()) {
            char buf[256];
            sprintf(buf, "%d.%d.%d.%d", t[0], t[1], t[2], t[3]);
            ans.push_back(buf);
            return;
        }
        for(int i = 1; i <= min(3, (int)s.size()); ++i) {
            if (s[0] == '0' && i > 1) continue;
            int ii = atoi(s.substr(0, i).c_str());
            if (ii > 255) continue;
            t.push_back(ii);
            go(k + 1, s.substr(i), t);
            t.pop_back();
        }
    }
  public:
    vector<string> genIp(string &s) {
        // Your code here
        ans.clear();
        vector<int> t;
        go(0, s, t);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends
