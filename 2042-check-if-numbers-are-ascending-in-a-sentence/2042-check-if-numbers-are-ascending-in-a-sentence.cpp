class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> nums;
        for (int i = 0; i < s.size(); i++)
        {
            int curr_index=i;
            if (s[curr_index] >= '0' && s[curr_index] <= '9')
            {
                int temp = s[curr_index] - '0';
                if (s[curr_index + 1] >= '0' && s[curr_index + 1] <= '9')
                {
                    temp = temp * 10 + (s[curr_index + 1] - '0');
                    i++;
                    if (s[curr_index + 2] >= '0' && s[curr_index + 2] <= '9')
                    {
                        temp = temp * 10 + (s[curr_index + 2] - '0');
                        i++;
                    }
                }
                nums.push_back(temp);
            }
        }
        for (int i = 1; i < nums.size() ; i++)
            if(nums[i]<=nums[i-1])
                return false;
        return true;
    }
};