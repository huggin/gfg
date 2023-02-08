//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
    int isValid(string s) {
            // code here
        if (count(s.begin(), s.end(), '.') != 3) return 0;
        vector<string> v(4);
        auto it = s.find('.');
        v[0] = s.substr(0, it);
        auto it2 = s.find('.', it+1);
        v[1] = s.substr(it+1, it2-it-1);
        auto it3 = s.find('.', it2+1);
        v[2] = s.substr(it2+1, it3-it2-1);
        v[3] = s.substr(it3+1);
        //for(auto c : v)
        //    cout << c << endl;
        for(int i = 0; i < 4; ++i) {
            if (v[i].size() == 0 || v[i].size() > 3) return 0;
            if (v[i].size() > 1 && v[i][0] == '0') return 0;
            int ip = 0;
            for(int j = 0; j < v[i].size(); ++j) {
                if (v[i][j] < '0' || v[i][j] > '9') return 0;
                ip = ip * 10 +  (v[i][j] - '0');
            }
            if (ip > 255) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
