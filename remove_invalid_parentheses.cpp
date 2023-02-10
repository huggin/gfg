//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
    vector<string> ans;
    int n;
    string S;
    int ma;
    
    bool valid(const string& s) {
        stack<char> sc;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                sc.push('(');
            } else if (s[i] == ')') {
                if (sc.empty()) return false;
                sc.pop();
            } 
        }
        return sc.empty();
    }
    
    void solve(int k, string& t) {
        if (k == n) {
            if (t.size() >= ma && valid(t)) {
                ans.push_back(t);
                ma = t.size();
            }
            return;
        }
        
        t.push_back(S[k]);
        solve(k+1, t);
        t.pop_back();
        solve(k+1, t);
    }
  public:
    vector<string> removeInvalidParentheses(string s) {
        // code here
        n = s.size();
        S = s;
        string t;
        ma = 0;
        solve(0, t);
        int len = 0;
        for(int i = 0; i < ans.size(); ++i) {
            len = max(len, (int)ans[i].size());
        }
        vector<string> v;
        for(int i = 0; i < ans.size(); ++i) {
            if (ans[i].size() == len) {
                v.push_back(ans[i]);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return v;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends
