//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void healper(int n , string s , vector<string> &v){
        if(s.size() == n){
            v.push_back(s);
            return;
        }
        
        healper(n , s+"0" , v);
        if(s[s.size()-1] != '1')
            healper(n , s+"1" , v);
            
    }
    void generateBinaryStrings(int num){
        //Write your code
        vector<string> v;
        healper(num , "0" , v);
        healper(num , "1" , v);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<" ";
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends