//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string rremove(string s){
        // code here
        string ans;
        ans.reserve(s.size());
        while(true) {
            bool finish = true;
            for(int i = 0; i < s.size(); ) {
                if (ans.size() == 0) {
                    ans += s[i++];
                } else {
                    if (s[i] == ans[ans.size() - 1]) {
                        finish = false;
                        char c = s[i];
                        while(c == s[i]) {
                            ++i;
                        }
                        ans.pop_back();
                        ans += s[i++];
                    } else {
                        ans += s[i++];
                    }
                }
            }
            if (finish) return ans;
            s = ans;
            ans.clear();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends
