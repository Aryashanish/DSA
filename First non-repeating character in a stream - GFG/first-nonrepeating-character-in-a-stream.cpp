//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int n = A.size();
            unordered_map<char,pair<int,int>> mp; //char,counts,index of coming
            string ans="";
            for(int i=0;i<n;i++){
                
                char ch='#';
                int mini = n;
                mp[A[i]].first++;
                mp[A[i]].second = i;
                for(auto it:mp){
                    if(it.second.first == 1){
                        if(it.second.second < mini){
                            mini = it.second.second;
                            ch = it.first;
                        }
                    }
                }
                ans+=ch;
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