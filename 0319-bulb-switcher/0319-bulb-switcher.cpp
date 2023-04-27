class Solution {
public:
    int bulbSwitch(int n) {
        double t = sqrt(n);
        return (int)floor(t);
    }
};