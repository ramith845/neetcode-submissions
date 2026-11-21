class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (const auto& word : strs) {
            groups[getHashString(word)].push_back(word);
        }

        std::vector<std::vector<std::string>> res{};
        for (const auto& key : groups) {
            res.push_back(std::move(key.second));
        }

        return res;
    }

   private:
    static std::string getHashString(const std::string& str) {
        std::array<int, 26> hashArr{0};
        for (const auto l : str) {
            hashArr[int(l - 'a')]++;
        }
        std::string hashStr{"#"};
        for (size_t i = 0; i < hashArr.size(); i++) {
            hashStr += ',' + to_string(hashArr[i]);
        }
        return hashStr;
    }
};
