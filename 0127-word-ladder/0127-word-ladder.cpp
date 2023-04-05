class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string , int>> q;
        q.push({beginWord , 1});
        unordered_set<string> st(wordList.begin() , wordList.end());
        st.erase(beginWord);
        
        while(!q.empty()){
            auto it = q.front();
            string word = it.first;
            int step = it.second;
            q.pop();
            
            if(word == endWord)
                return step;
            
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                
                word[i] = original;
            }
        }
        
        return 0;
    }
};