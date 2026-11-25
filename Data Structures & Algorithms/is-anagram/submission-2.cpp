class Solution {
   public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        std::unordered_map<char, int> freqS;
        std::unordered_map<char, int> freqT;

        for (int i = 0; i < s.length(); i++) {
            freqS[s[i]]++;
            freqT[t[i]]++;
        }

        // for (int i = 0; i < s.size(); i++)
        // {
        //     if(freqS[s[i]] != freqT[s[i]])
        //         return false;
        // }


        return freqT == freqS;
    }
};
