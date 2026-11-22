class Solution {
   public:
    auto topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freqMap;
        for (const auto& num : nums) freqMap[num]++;

       std::vector<std::vector<int>> buckets(n + 1);
        for (const auto& [num, freq] : freqMap) {
            buckets[freq].push_back(num);
        }

        std::vector<int> res;
        int i{0};
        for (auto bucket = buckets.rbegin(); bucket != buckets.rend(); ++bucket)
        {
            if(i == k) break;
            for(const auto ele : *bucket)
            {
                res.push_back(ele);
                i++;
            }
        }
        
        return res;
    }
};
