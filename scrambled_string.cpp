//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    bool isAnagram(const string& s1, const string& s2, int l1, int r1, int l2, int r2) {
        unordered_map<char, int> m;
        for(int i=l1; i<=r1; ++i) {
            ++m[s1[i]];
        }
        for(int i=l2; i<=r2; ++i) {
            if (--m[s2[i]] < 0) return false;
        }
        return true;
    }
    
    bool isScramble(const string& s1, const string& s2, int l1, int r1, int l2, int r2) {
        if (r1 - l1 <= 2) return true;
        for(int i = l1; i < r1; ++i) {
            if (isAnagram(s1, s2, l1, i, l2, l2+i-l1)) {
                return isScramble(s1, s2, l1, i, l2, l2+i-l1) 
                    && isScramble(s1, s2, i+1, r1, r2+i+1-r1, r2);
            }
            if (isAnagram(s1, s2, l1, i, r2+l1-i, r2)) {
                return isScramble(s1, s2, l1, i, r2+l1-i, r2) 
                    && isScramble(s1, s2, i+1, r1, l2, r1+l2-i-1);
            }
        }
        return false;
    }
    public:
    bool isScramble(string S1, string S2){
        //code here
        if (!isAnagram(S1, S2, 0, S1.size()-1, 0, S2.size()-1)) return false;
        return isScramble(S1, S2, 0, S1.size() - 1, 0, S2.size() - 1);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
