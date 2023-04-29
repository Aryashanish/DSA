//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void healper(vector<string> &ans , string temp , int i , string &s){
            if(i == s.size()){
                if(temp != "")
                    ans.push_back(temp);
                return;
            }
            
            healper(ans,temp+s[i],i+1,s);
            healper(ans,temp,i+1,s);
        }
        
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    healper(ans , "" , 0 , s);
		    sort(ans.begin() , ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends