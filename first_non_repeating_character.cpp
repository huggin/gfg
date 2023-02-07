//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans(A.size(), A[0]);
		    list<char> l;
		    int used[256] = {0};
		    for(int i = 0; i < A.size(); ++i) {
		        if (find(l.begin(), l.end(), A[i]) == l.end()) {
		            l.push_back(A[i]);
		        } else {
		            used[A[i]]++;
		        }
		        bool flag = true;
		        for(auto item : l) {
		            if (used[item] == 0) {
		                ans[i] = item;
		                flag = false;
		                break;
		            } 
		        }
		        if (flag) {
		            ans[i] = '#';
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
