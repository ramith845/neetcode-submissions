class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> count;

        for(auto num : nums)
        {
            if(!count.count(num))
            {
                count[num]++;
            }
            else
                return true;
        }

        return false;
    }
};