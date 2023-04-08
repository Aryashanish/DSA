//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string str = "";
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(st.size()>0)
                    str += '(';
                st.push('(');
            }else{
                st.pop();
                if(st.size() > 0)
                    str += ')';
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends