class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0 , j = 0;
        string str = "";
        bool flag = true;
        while(i<word1.size() && j<word2.size()){
            if(flag)
                str += word1[i++];
            else
                str += word2[j++];
            flag = !flag;
        }
        
        for(;i<word1.size();i++)
            str += word1[i];
        
        for(;j<word2.size();j++)
            str += word2[j];
        
        return str;
    }
};