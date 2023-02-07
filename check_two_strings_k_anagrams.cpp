//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        // code here
        if (str1.size() != str2.size()) return false;
        int c1[26] = {0}, c2[26] = {0};
        for(int i = 0; i < str1.size(); ++i) {
            c1[str1[i]-'a']++;
            c2[str2[i]-'a']++;
        }
        int same = 0;
        for(int i = 0; i < 26; ++i) {
            same += min(c1[i], c2[i]);
        }
        return str1.size() - same <= k;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}
// } Driver Code Ends
