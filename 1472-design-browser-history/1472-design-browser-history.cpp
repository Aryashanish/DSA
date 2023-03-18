class BrowserHistory {
public:
    vector<string> v;
    int i;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        i = 0;
    }
    
    void visit(string url) {
        int j = v.size()-1;
        while(j>i){
            v.pop_back();
            j--;
        }
        i++;
        v.push_back(url);
    }
    
    string back(int steps) {
        i = i - steps;
        if(i < 0)
            i = 0;
        return v[i];
    }
    
    string forward(int steps) {
        i += steps;
        if(i >= v.size())
            i = v.size()-1;
        return v[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */