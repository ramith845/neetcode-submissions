class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::string, std::vector<std::string>> groups;
        for (auto& word : strs) {
            auto key = word;
            std::sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        std::vector<std::vector<std::string>> res;
        for (auto& key : groups) {
            res.push_back(std::move(key.second));
        }

        return res;
    }
};
