//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if (S > D * 9) return "-1";
        string ans;
        while(S >= 9) {
            ans.push_back('9');
            S -= 9;
        }
        if (S == 0) {
            if (ans.size() == D) return ans;
            ans.pop_back();
            ans.push_back('8');
            while (ans.size() < D-1) {
                ans.push_back('0');
            }
            ans.push_back('1');
        } else {
            if (D == ans.size()+1) {
                ans.push_back(S+'0');
                reverse(ans.begin(), ans.end());
                return ans;
            }
            ans.push_back(S-1+'0');
            while (ans.size() < D-1) {
                ans.push_back('0');
            }
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
