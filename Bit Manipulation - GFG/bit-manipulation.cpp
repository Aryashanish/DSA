//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        string binary = bitset<32>(num).to_string();
        int n = binary.size();
        
        cout<<binary[n-i]<<" ";
        
        if(binary[n-i] == '1')
            cout<<num<<" ";
        else{
            binary[n-i] = '1';
            cout<<stoi(binary , 0 , 2)<<" ";
        }
        
        binary[n-i] = '0';
        cout<<stoi(binary , 0 , 2)<<" ";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends