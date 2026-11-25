class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::cout << "Munde magane \n";
        std::unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            heap;

        for (auto [n, f] : freq) {
            heap.push(std::make_pair(f, n));
            if (heap.size() > k) heap.pop();
        }

        std::vector<int> res;
        for (size_t i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
