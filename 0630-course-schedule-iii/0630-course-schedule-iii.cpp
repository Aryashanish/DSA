class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , comp);
        
        int t = 0;
        priority_queue<int> pq;
        
        for(int i=0; i<courses.size(); i++){
            int duration = courses[i][0];
            int deadline = courses[i][1];
            t += duration;
            pq.push(duration);
            
            if(t > deadline){
                t -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};