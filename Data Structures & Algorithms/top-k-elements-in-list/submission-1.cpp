class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        for (const auto& num : nums) freq[num]++;

        std::vector<std::pair<int, int>> numFreq;
        for (const auto& [key, value] : freq) {
            numFreq.push_back(std::make_pair(key, value));
        }

        std::sort(numFreq.begin(), numFreq.end(),
                  [](std::pair<int, int> a, std::pair<int, int> b) { return a.second > b.second; });
        
        std::vector<int> res;
        int i{0};
        for (const auto& [num, freq] : numFreq) {
            if(k==i)
                break;
            res.push_back(num);
            i++;
        }
        return res;
    }
};
